import { minesweeperState } from '../state.js';

const PRESETS = {
  beginner: { width: 9, height: 9, mines: 10, label: 'beginner' },
  intermediate: { width: 16, height: 16, mines: 40, label: 'intermediate' },
  expert: { width: 30, height: 16, mines: 99, label: 'expert' },
};

const MS_ASSETS = {
  mine: 'assets/minesweeper/mine.svg',
  flag: 'assets/minesweeper/flag.svg',
  faceIdle: 'assets/minesweeper/face-idle.svg',
  faceWin: 'assets/minesweeper/face-win.svg',
  faceBoom: 'assets/minesweeper/face-boom.svg',
};

function isMobileViewport() {
  // Check if device has touch capability and small width
  // Avoid false positives from resized desktop browsers
  const isTouchDevice = () => {
    return (
      (navigator.maxTouchPoints > 0) ||
      (navigator.msMaxTouchPoints > 0) ||
      window.matchMedia('(hover: none) and (pointer: coarse)').matches
    );
  };
  return window.innerWidth <= 768 && isTouchDevice();
}

function getUi() {
  return {
    root: document.getElementById('minesweeper-root'),
    board: document.getElementById('ms-board'),
    minesLeft: document.getElementById('ms-mines-left'),
    timer: document.getElementById('ms-timer'),
    status: document.getElementById('ms-status'),
    flagModeBtn: document.getElementById('ms-flag-mode-btn'),
    difficultyValue: document.getElementById('ms-difficulty-value'),
  };
}

function boardIndex(x, y) {
  return y * minesweeperState.width + x;
}

function inBounds(x, y) {
  return x >= 0 && x < minesweeperState.width && y >= 0 && y < minesweeperState.height;
}

function neighbors(x, y) {
  const out = [];
  for (let dy = -1; dy <= 1; dy += 1) {
    for (let dx = -1; dx <= 1; dx += 1) {
      if (dx === 0 && dy === 0) continue;
      const nx = x + dx;
      const ny = y + dy;
      if (inBounds(nx, ny)) out.push([nx, ny]);
    }
  }
  return out;
}

function makeCell() {
  return {
    mine: false,
    revealed: false,
    flagged: false,
    adjacent: 0,
    exploded: false,
  };
}

function createEmptyBoard() {
  const total = minesweeperState.width * minesweeperState.height;
  minesweeperState.board = Array.from({ length: total }, makeCell);
  minesweeperState.revealedCount = 0;
  minesweeperState.flagsPlaced = 0;
}

function stopTimer() {
  if (minesweeperState.timerId) {
    window.clearInterval(minesweeperState.timerId);
    minesweeperState.timerId = 0;
  }
}

function startTimer() {
  if (minesweeperState.timerId || minesweeperState.gameOver || !minesweeperState.running) return;
  minesweeperState.timerId = window.setInterval(() => {
    if (!minesweeperState.running || minesweeperState.gameOver) return;
    minesweeperState.timer += 1;
    syncHud();
  }, 1000);
}

function withPreset(name) {
  const preset = PRESETS[name] || PRESETS.beginner;
  minesweeperState.difficulty = name in PRESETS ? name : 'beginner';
  minesweeperState.width = preset.width;
  minesweeperState.height = preset.height;
  minesweeperState.mines = preset.mines;
}

function randomMinePositions(excludedSet) {
  const total = minesweeperState.width * minesweeperState.height;
  const pool = [];
  for (let i = 0; i < total; i += 1) {
    if (!excludedSet.has(i)) pool.push(i);
  }

  for (let i = pool.length - 1; i > 0; i -= 1) {
    const j = Math.floor(Math.random() * (i + 1));
    const tmp = pool[i];
    pool[i] = pool[j];
    pool[j] = tmp;
  }

  return pool.slice(0, minesweeperState.mines);
}

function prepareMines(firstX, firstY) {
  const safe = new Set([boardIndex(firstX, firstY)]);
  neighbors(firstX, firstY).forEach(([nx, ny]) => safe.add(boardIndex(nx, ny)));

  const mines = randomMinePositions(safe);
  mines.forEach(index => {
    minesweeperState.board[index].mine = true;
  });

  for (let y = 0; y < minesweeperState.height; y += 1) {
    for (let x = 0; x < minesweeperState.width; x += 1) {
      const idx = boardIndex(x, y);
      if (minesweeperState.board[idx].mine) continue;
      let count = 0;
      neighbors(x, y).forEach(([nx, ny]) => {
        if (minesweeperState.board[boardIndex(nx, ny)].mine) count += 1;
      });
      minesweeperState.board[idx].adjacent = count;
    }
  }
}

function formatCounter(value) {
  const abs = Math.min(999, Math.abs(value));
  const prefix = value < 0 ? '-' : '';
  return `${prefix}${String(abs).padStart(3, '0')}`;
}

function syncHud() {
  const ui = getUi();
  if (!ui.root) return;

  const minesLeft = minesweeperState.mines - minesweeperState.flagsPlaced;
  if (ui.minesLeft) ui.minesLeft.textContent = formatCounter(minesLeft);
  if (ui.timer) ui.timer.textContent = formatCounter(minesweeperState.timer);
  if (ui.status) {
    let iconSrc = MS_ASSETS.faceIdle;
    if (minesweeperState.gameOver && minesweeperState.won) {
      iconSrc = MS_ASSETS.faceWin;
    } else if (minesweeperState.gameOver) {
      iconSrc = MS_ASSETS.faceBoom;
    }
    ui.status.innerHTML = `<img class="ms-reset-icon" src="${iconSrc}" alt="game status icon"><span class="ms-reset-label">restart game</span>`;
  }

  if (ui.flagModeBtn) {
    ui.flagModeBtn.classList.toggle('active', minesweeperState.flagMode);
    ui.flagModeBtn.setAttribute('aria-pressed', minesweeperState.flagMode ? 'true' : 'false');
  }

  if (ui.difficultyValue) {
    const label = PRESETS[minesweeperState.difficulty]?.label || 'beginner';
    ui.difficultyValue.textContent = label;
  }

  document.querySelectorAll('.ms-difficulty-btn').forEach(btn => {
    const active = btn.textContent?.trim() === minesweeperState.difficulty;
    btn.classList.toggle('active', active);
  });
}

function revealAllMines() {
  minesweeperState.board.forEach(cell => {
    if (cell.mine) cell.revealed = true;
  });
}

function maybeWin() {
  const safeCells = minesweeperState.width * minesweeperState.height - minesweeperState.mines;
  if (minesweeperState.revealedCount >= safeCells) {
    minesweeperState.gameOver = true;
    minesweeperState.won = true;
    minesweeperState.running = false;
    stopTimer();
    renderBoard();
    syncHud();
    return true;
  }
  return false;
}

function loseAt(cell) {
  cell.exploded = true;
  cell.revealed = true;
  minesweeperState.gameOver = true;
  minesweeperState.won = false;
  minesweeperState.running = false;
  stopTimer();
  revealAllMines();
  renderBoard();
  syncHud();
}

function floodReveal(startX, startY) {
  const queue = [[startX, startY]];

  while (queue.length) {
    const [x, y] = queue.pop();
    const idx = boardIndex(x, y);
    const cell = minesweeperState.board[idx];

    if (cell.revealed || cell.flagged) continue;
    cell.revealed = true;
    minesweeperState.revealedCount += 1;

    if (cell.adjacent !== 0) continue;
    neighbors(x, y).forEach(([nx, ny]) => {
      const neighbor = minesweeperState.board[boardIndex(nx, ny)];
      if (!neighbor.revealed && !neighbor.flagged) queue.push([nx, ny]);
    });
  }
}

function revealCell(x, y) {
  if (!inBounds(x, y) || minesweeperState.gameOver) return;

  const cell = minesweeperState.board[boardIndex(x, y)];
  if (cell.revealed || cell.flagged) return;

  if (!minesweeperState.firstRevealDone) {
    prepareMines(x, y);
    minesweeperState.firstRevealDone = true;
    startTimer();
  }

  if (cell.mine) {
    loseAt(cell);
    return;
  }

  if (cell.adjacent === 0) {
    floodReveal(x, y);
  } else {
    cell.revealed = true;
    minesweeperState.revealedCount += 1;
  }

  renderBoard();
  syncHud();
  maybeWin();
}

function toggleFlag(x, y) {
  if (!inBounds(x, y) || minesweeperState.gameOver) return;
  const cell = minesweeperState.board[boardIndex(x, y)];
  if (cell.revealed) return;

  cell.flagged = !cell.flagged;
  minesweeperState.flagsPlaced += cell.flagged ? 1 : -1;
  renderBoard();
  syncHud();
}

function chordReveal(x, y) {
  if (!inBounds(x, y) || minesweeperState.gameOver) return;
  const cell = minesweeperState.board[boardIndex(x, y)];
  if (!cell.revealed || cell.adjacent === 0) return;

  const nbs = neighbors(x, y);
  const flagged = nbs.reduce((count, [nx, ny]) => {
    return count + (minesweeperState.board[boardIndex(nx, ny)].flagged ? 1 : 0);
  }, 0);

  if (flagged !== cell.adjacent) return;

  nbs.forEach(([nx, ny]) => {
    const neighbor = minesweeperState.board[boardIndex(nx, ny)];
    if (!neighbor.flagged) revealCell(nx, ny);
  });
}

function cellMarkup(x, y, cell) {
  const classes = ['ms-cell'];
  if (cell.revealed) classes.push('revealed');
  if (cell.flagged && !cell.revealed) classes.push('flagged');
  if (cell.mine && cell.revealed) classes.push('mine');
  if (cell.exploded) classes.push('exploded');

  let inner = '';
  if (cell.flagged && !cell.revealed) {
    inner = `<img class="ms-cell-icon" src="${MS_ASSETS.flag}" alt="flag">`;
  } else if (cell.revealed && cell.mine) {
    inner = `<img class="ms-cell-icon" src="${MS_ASSETS.mine}" alt="mine">`;
  } else if (cell.revealed && cell.adjacent > 0) {
    inner = `<span class="ms-num ms-num-${cell.adjacent}">${cell.adjacent}</span>`;
  }

  return `<button class="${classes.join(' ')}" data-role="cell" data-x="${x}" data-y="${y}" aria-label="cell ${x + 1},${y + 1}">${inner}</button>`;
}

function getCellSizePx() {
  if (minesweeperState.difficulty === 'expert') return 20;
  if (minesweeperState.difficulty === 'intermediate') return 24;
  return 28;
}

function renderBoard() {
  const ui = getUi();
  if (!ui.board || !ui.root) return;

  ui.root.style.setProperty('--ms-cell-size', `${getCellSizePx()}px`);

  ui.board.style.gridTemplateColumns = `repeat(${minesweeperState.width}, var(--ms-cell-size))`;
  let html = '';

  for (let y = 0; y < minesweeperState.height; y += 1) {
    for (let x = 0; x < minesweeperState.width; x += 1) {
      html += cellMarkup(x, y, minesweeperState.board[boardIndex(x, y)]);
    }
  }

  ui.board.innerHTML = html;
}

function newGame() {
  minesweeperState.running = true;
  minesweeperState.gameOver = false;
  minesweeperState.won = false;
  minesweeperState.firstRevealDone = false;
  minesweeperState.flagMode = false;
  minesweeperState.timer = 0;
  stopTimer();
  createEmptyBoard();
  renderBoard();
  syncHud();
}

function boardCellFromEventTarget(target) {
  if (!target) return null;
  const cell = target.closest('[data-role="cell"]');
  if (!cell) return null;

  const x = Number(cell.getAttribute('data-x'));
  const y = Number(cell.getAttribute('data-y'));
  if (!Number.isInteger(x) || !Number.isInteger(y)) return null;
  return { x, y };
}

function onBoardClick(event) {
  const point = boardCellFromEventTarget(event.target);
  if (!point) return;

  if (minesweeperState.flagMode) {
    toggleFlag(point.x, point.y);
    return;
  }

  revealCell(point.x, point.y);
}

function onBoardContextMenu(event) {
  const point = boardCellFromEventTarget(event.target);
  if (!point) return;

  event.preventDefault();
  toggleFlag(point.x, point.y);
}

function onBoardDoubleClick(event) {
  const point = boardCellFromEventTarget(event.target);
  if (!point) return;

  event.preventDefault();
  chordReveal(point.x, point.y);
}

function bindBoardEvents() {
  const ui = getUi();
  if (!ui.board || minesweeperState.bound) return;

  ui.board.addEventListener('click', onBoardClick);
  ui.board.addEventListener('contextmenu', onBoardContextMenu);
  ui.board.addEventListener('dblclick', onBoardDoubleClick);
  minesweeperState.bound = true;
}

export function toggleMinesweeperFlagMode() {
  minesweeperState.flagMode = !minesweeperState.flagMode;
  syncHud();
}

export function setMinesweeperDifficulty(name) {
  withPreset(name);
  newGame();
}

export function resetMinesweeperGame() {
  newGame();
}

export function startMinesweeperGame() {
  if (isMobileViewport()) {
    stopMinesweeperGame();
    return;
  }

  const ui = getUi();
  if (!ui.root || !ui.board) return;

  if (!minesweeperState.initialized) {
    bindBoardEvents();
    minesweeperState.initialized = true;
    withPreset(minesweeperState.difficulty || 'beginner');
    newGame();
    return;
  }

  minesweeperState.running = true;
  if (minesweeperState.firstRevealDone && !minesweeperState.gameOver) {
    startTimer();
  }
  renderBoard();
  syncHud();
}

export function stopMinesweeperGame() {
  minesweeperState.running = false;
  stopTimer();
}
