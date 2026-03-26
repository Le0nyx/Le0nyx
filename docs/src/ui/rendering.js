import { PORTFOLIO_CONTENT } from '../data/portfolio-data.js';

function tagToneClass(tag) {
  return tag.tone ? ` ${tag.tone}` : '';
}

export function renderTagList(tags) {
  return `<div class="tag-list">${tags
    .map(tag => `<span class="tag${tagToneClass(tag)}">${tag.text}</span>`)
    .join('')}</div>`;
}

export function renderWindowBody(body) {
  if (body.type === 'about') {
    const avatarContent = body.avatarSrc
      ? `<img class="avatar-img" src="${body.avatarSrc}" alt="${body.avatarAlt || 'Profile picture'}">`
      : body.avatarEmoji;
    const sections = body.sections
      .map(section => `<div class="win-h3">${section.heading}</div><div class="win-p">${section.text}</div>`)
      .join('');
    const interests = renderTagList(body.interests.map(text => ({ text })));
    return `
      <div class="avatar-area">
        <div class="avatar-circle">${avatarContent}</div>
        <div>
          <div class="win-h1">${body.name}</div>
          <div class="win-h2">${body.subtitle}</div>
        </div>
      </div>
      <div class="win-p">${body.intro}</div>
      ${renderTagList(body.primaryTags)}
      <hr class="win-divider">
      ${sections}
      <div class="win-h3">${body.interestsHeading}</div>
      ${interests}
    `;
  }

  if (body.type === 'work') {
    const cards = body.projects
      .map(project => `
        <div class="project-card">
          <div class="project-header">
            <div class="project-emoji">${project.emoji}</div>
            <div class="project-title">${project.title}</div>
            <div class="project-year">${project.year}</div>
          </div>
          <div class="project-body">
            <div class="project-desc">${project.description}</div>
            <div class="tag-list" style="margin-top:8px">${project.tags
              .map(tag => `<span class="tag${tagToneClass(tag)}">${tag.text}</span>`)
              .join('')}</div>
          </div>
        </div>
      `)
      .join('');
    return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      ${cards}
      <hr class="win-divider">
      <div class="win-p" style="font-size:11px">${body.footerText}</div>
    `;
  }

  if (body.type === 'skills') {
    const iconSkills = (body.iconSkills || [])
      .map(
        skill =>
          `<div class="skill-icon-pill ${skill.tone || ''}"><img src="assets/skills/${skill.icon}.svg" alt="${skill.label} icon"><span>${skill.label}</span></div>`
      )
      .join('');
    const groups = body.groups
      .map(group => {
        const bars = group.bars
          .map(
            bar =>
              `<div class="skill-bar-row"><span class="skill-name">${bar.name}</span><div class="skill-track"><div class="skill-fill" style="width:${bar.width}%;animation-delay:${bar.delay}"></div></div></div>`
          )
          .join('');
        return `<div class="win-h3">${group.heading}</div>${bars}`;
      })
      .join('');
    return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      <div class="win-h3">${body.iconSkillsHeading || 'icon skills'}</div>
      <div class="skill-icon-grid">${iconSkills}</div>
      ${groups}
      <div class="win-h3">${body.toolsHeading}</div>
      ${renderTagList(body.tools.map(text => ({ text })))}
    `;
  }

  if (body.type === 'qa') {
    const items = (body.items || [])
      .map((item, i) => {
        const answer = (item.answer || '').trim() || 'your answer here...';
        return `
          <div class="qa-item">
            <div class="qa-q">${i + 1}. ${item.question}</div>
            <div class="qa-a">${answer}</div>
          </div>
        `;
      })
      .join('');

    return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      <div class="win-p">${body.intro}</div>
      <div class="qa-group">${items}</div>
      <hr class="win-divider">
      <div class="win-p" style="font-size:11px">${body.footerText}</div>
    `;
  }

  if (body.type === 'github') {
    const avatarContent = body.avatarSrc
      ? `<img class="avatar-img" src="${body.avatarSrc}" alt="${body.avatarAlt || 'GitHub profile picture'}">`
      : '🐈‍⬛';
    return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      <div class="github-card">
        <div class="avatar-circle github-avatar">${avatarContent}</div>
        <div>
          <div class="github-name">${body.profileName}</div>
          <a class="github-link" href="${body.profileUrl}" target="_blank" rel="noopener noreferrer" onclick="showToast('Opening GitHub...')">${body.profileUrl}</a>
        </div>
      </div>
      ${body.stats ? `<div class="win-p">${body.stats}</div>` : ''}
      <hr class="win-divider">
      <div class="win-p" style="font-size:10px">${body.footerText}</div>
    `;
  }

  if (body.type === 'dino') {
    return `
      <div class="dino-head">
        <div>
          <div class="win-h1">${body.heading}</div>
          <div class="win-h2">${body.subheading}</div>
        </div>
        <div class="dino-score" id="dino-score">score: 0</div>
      </div>
      <div class="dino-mobile-note">${body.mobileNote}</div>
      <div class="dino-stage-wrap" id="dino-stage-wrap">
        <canvas id="dino-canvas" width="1000" height="420" aria-label="Dino game canvas"></canvas>
      </div>
      <div class="dino-controls">jump: space / w / arrow up · duck: s / arrow down · restart: r</div>
    `;
  }

  if (body.type === 'minesweeper') {
    return `
      <div id="minesweeper-root" class="ms-shell">
        <div class="dino-head">
          <div>
            <div class="win-h1">${body.heading}</div>
            <div class="win-h2">${body.subheading}</div>
          </div>
          <button class="ms-reset" id="ms-status" onclick="resetMinesweeperGame()" title="new game"><img class="ms-reset-icon" src="assets/minesweeper/face-idle.svg" alt="game status icon"><span class="ms-reset-label">restart game</span></button>
        </div>

        <div class="ms-mobile-note">${body.mobileNote || 'Sorry, this game is only available in desktop view.'}</div>

        <div class="ms-hud-row">
          <div class="ms-counter"><img class="ms-counter-icon" src="assets/minesweeper/mine.svg" alt="mine icon"> <span id="ms-mines-left">010</span></div>
          <div class="ms-difficulty-controls" role="group" aria-label="Minesweeper difficulty">
            <button class="ms-difficulty-btn" onclick="setMinesweeperDifficulty('beginner')">beginner</button>
            <button class="ms-difficulty-btn" onclick="setMinesweeperDifficulty('intermediate')">intermediate</button>
            <button class="ms-difficulty-btn" onclick="setMinesweeperDifficulty('expert')">expert</button>
          </div>
          <div class="ms-counter"><img class="ms-counter-icon" src="assets/minesweeper/timer.svg" alt="timer icon"> <span id="ms-timer">000</span></div>
        </div>

        <div class="ms-toolbar">
          <button id="ms-flag-mode-btn" class="ms-flag-mode" onclick="toggleMinesweeperFlagMode()" aria-pressed="false"><img class="ms-button-icon" src="assets/minesweeper/flag.svg" alt="flag icon"> flag mode (single click for flag)</button>
          <div class="ms-selected-difficulty">mode: <span id="ms-difficulty-value">beginner</span></div>
        </div>

        <div class="ms-board-wrap">
          <div id="ms-board" class="ms-board" aria-label="Minesweeper board"></div>
        </div>
      </div>
    `;
  }

  return '';
}

export function renderWindows() {
  const root = document.getElementById('windows-root');
  if (!root) return;

  root.innerHTML = PORTFOLIO_CONTENT.windows
    .map(windowConfig => {
      const frame = windowConfig.frame;
      return `
        <div id="${windowConfig.id}" class="window hidden" style="width:${frame.width}px;height:${frame.height}px;top:${frame.top}px;left:${frame.left}px;">
          <div class="titlebar">
            <div class="window-controls">
              <button class="wc wc-close" onclick="closeWindow('${windowConfig.id}')"></button>
              <button class="wc wc-min" onclick="minimizeWindow('${windowConfig.id}')"></button>
              <button class="wc wc-max" onclick="maximizeWindow('${windowConfig.id}')"></button>
            </div>
            <div class="titlebar-title">${windowConfig.titleIcon} ${windowConfig.titleText}</div>
            <div style="width:52px"></div>
          </div>
          <div class="window-body">${renderWindowBody(windowConfig.body)}</div>
          <div class="resize-handle"></div>
        </div>
      `;
    })
    .join('');
}

export function renderDesktopIcons(desktopIconOrder, windowMeta) {
  const iconGrid = document.getElementById('icon-grid');
  if (!iconGrid) return;

  iconGrid.innerHTML = '';
  desktopIconOrder.forEach(id => {
    if (id === '__spacer__') {
      const spacer = document.createElement('div');
      spacer.className = 'desktop-icon desktop-icon-spacer';
      spacer.setAttribute('aria-hidden', 'true');
      iconGrid.appendChild(spacer);
      return;
    }

    const meta = windowMeta[id];
    if (!meta) return;

    const icon = document.createElement('div');
    icon.className = id === 'dino' ? 'desktop-icon desktop-icon-dino' : 'desktop-icon';
    icon.innerHTML = `<div class="icon-emoji">${meta.icon}</div><div class="icon-label">${meta.label}</div>`;
    icon.addEventListener('click', () => window.openWindow(id));
    iconGrid.appendChild(icon);
  });
}

export function renderDesktopMeta() {
  const hintEmoji = document.getElementById('hint-emoji');
  const hintText = document.getElementById('hint-text');
  const desktopLabel = document.getElementById('desktop-label');

  if (hintEmoji) hintEmoji.textContent = PORTFOLIO_CONTENT.desktop.hintEmoji;
  if (hintText) hintText.textContent = PORTFOLIO_CONTENT.desktop.hintText;
  if (desktopLabel) {
    desktopLabel.textContent = PORTFOLIO_CONTENT.desktop.labelText;
    desktopLabel.href = PORTFOLIO_CONTENT.desktop.labelHref;
  }
}
