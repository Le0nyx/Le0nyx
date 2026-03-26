import { uiState } from '../state.js';
import { TASKBAR_HEIGHT } from '../config.js';
import { clampWindowToViewport } from './styles.js';
import { startDinoGame, stopDinoGame } from '../game/game.js';
import {
  startMinesweeperGame,
  stopMinesweeperGame,
  resetMinesweeperGame,
} from '../game/minesweeper.js';

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

export function focusWindow(id) {
  document.querySelectorAll('.window').forEach(w => w.classList.remove('focused'));
  const win = document.getElementById(id);
  if (!win) return;

  win.style.zIndex = ++uiState.zTop;
  win.classList.add('focused');
  Object.keys(uiState.taskbarWindows).forEach(k => {
    if (uiState.taskbarWindows[k]) uiState.taskbarWindows[k].classList.toggle('active', k === id);
  });
}

export function openWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;

  document.getElementById('hint').classList.add('gone');

  if (uiState.windowStates[id] === 'minimized') {
    win.classList.remove('minimized');
    uiState.windowStates[id] = 'open';
    focusWindow(id);
    updateTaskbar(id, 'open');
    if (id === 'dino') startDinoGame();
    if (id === 'minesweeper') startMinesweeperGame();
    return;
  }
  if (uiState.windowStates[id] === 'open') {
    focusWindow(id);
    if (id === 'dino') startDinoGame();
    if (id === 'minesweeper') startMinesweeperGame();
    return;
  }

  if (id === 'dino' && !isMobileViewport()) {
    const width = Math.floor(window.innerWidth * 0.78);
    const height = Math.floor((window.innerHeight - TASKBAR_HEIGHT) * 0.72);
    const finalW = Math.min(1180, Math.max(860, width));
    const finalH = Math.min(680, Math.max(540, height));
    win.style.width = `${finalW}px`;
    win.style.height = `${finalH}px`;
    win.style.left = `${Math.max(0, Math.floor((window.innerWidth - finalW) / 2))}px`;
    win.style.top = `${Math.max(8, Math.floor((window.innerHeight - TASKBAR_HEIGHT - finalH) / 2))}px`;
  }

  win.classList.remove('hidden');
  win.classList.add('window-opening');
  win.addEventListener('animationend', () => win.classList.remove('window-opening'), { once: true });
  clampWindowToViewport(win);
  uiState.windowStates[id] = 'open';
  focusWindow(id);
  addToTaskbar(id);
  if (id === 'dino') startDinoGame();
  if (id === 'minesweeper') startMinesweeperGame();
}

export function closeWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;
  win.classList.add('hidden');
  uiState.windowStates[id] = 'closed';
  removeFromTaskbar(id);
  if (id === 'dino') stopDinoGame();
  if (id === 'minesweeper') {
    stopMinesweeperGame();
    resetMinesweeperGame();
  }
}

export function minimizeWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;
  win.classList.add('minimized');
  uiState.windowStates[id] = 'minimized';
  updateTaskbar(id, 'minimized');
  if (id === 'dino') stopDinoGame();
  if (id === 'minesweeper') stopMinesweeperGame();
}

export function maximizeWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;

  const isMax = win.dataset.maximized === 'true';
  if (!isMax) {
    win.dataset.prevStyle = `left:${win.style.left};top:${win.style.top};width:${win.style.width};height:${win.style.height}`;
    win.style.left = '0px';
    win.style.top = '0px';
    win.style.width = 'calc(100vw)';
    win.style.height = 'calc(100vh - 52px)';
    win.dataset.maximized = 'true';
  } else {
    const prev = win.dataset.prevStyle;
    if (prev) {
      prev.split(';').forEach(s => {
        const [k, v] = s.split(':');
        if (k && v) win.style[k.trim()] = v.trim();
      });
    }
    win.dataset.maximized = 'false';
  }
}

function addToTaskbar(id) {
  if (uiState.taskbarWindows[id]) return;
  const taskbarLeft = document.getElementById('taskbar-left');
  const meta = window.windowMeta[id] || { icon: '🗔', label: id };
  const btn = document.createElement('div');
  btn.className = 'taskbar-btn active';
  btn.innerHTML = `<span class="tb-icon">${meta.icon}</span><span class="tb-label">${meta.label}</span>`;
  btn.onclick = () => {
    if (uiState.windowStates[id] === 'minimized') {
      openWindow(id);
    } else if (document.getElementById(id)?.classList.contains('focused')) {
      minimizeWindow(id);
    } else {
      focusWindow(id);
    }
  };
  taskbarLeft.appendChild(btn);
  uiState.taskbarWindows[id] = btn;
  Object.keys(uiState.taskbarWindows).forEach(k => {
    if (uiState.taskbarWindows[k]) uiState.taskbarWindows[k].classList.toggle('active', k === id);
  });
}

function removeFromTaskbar(id) {
  if (uiState.taskbarWindows[id]) {
    uiState.taskbarWindows[id].remove();
    uiState.taskbarWindows[id] = null;
  }
}

function updateTaskbar(id, state) {
  if (!uiState.taskbarWindows[id]) return;
  uiState.taskbarWindows[id].classList.toggle('active', state === 'open');
}
