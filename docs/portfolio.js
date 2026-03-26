const PROFILE = {
  githubUrl: 'https://github.com/Le0nyx',
  avatarUrl: 'https://github.com/Le0nyx.png',
};

const PORTFOLIO_CONTENT = {
  desktop: {
    hintEmoji: '👆',
    hintText: 'click the icons to explore',
    labelText: 'inspired by sharyap.com',
    labelHref: 'https://www.sharyap.com',
  },
  windows: [
    { // about me
      id: 'about',
      desktopIcon: '🪴',
      desktopLabel: 'about me',
      titleIcon: '🪴',
      titleText: 'about me',
      frame: { width: 520, height: 520, top: 60, left: 280 },
      body: {
        type: 'about',
        avatarSrc: PROFILE.avatarUrl,
        avatarAlt: 'Le0nyx profile picture',
        avatarEmoji: '✨',
        name: 'Leon',
        subtitle: 'student & developer',
        intro: "Hey! I'm a computer science student from northern Italy. I code in my freetime building apps and tinkering with electronics. Currently exploring Flutter, Ollama, and AI integration.",
        primaryTags: [
          { text: 'flutter', tone: 'accent' },
          { text: 'fullstack', tone: 'accent2' },
          { text: 'ai/ollama', tone: 'accent3' },
          { text: '3d-printing', tone: 'accent4' },
          { text: 'open source', tone: 'accent5' },
          { text: 'hackathons', tone: 'accent6' },
          { text: 'electronics', tone: 'accent7' },
          { text: 'coffee ☕', tone: 'accent8' },
        ],
        sections: [
          {
            heading: 'background',
            text: 'Passionate about creating solutions to complex problems. Started with web development and gradually moved into cross-platform mobile development with Flutter. Deeply interested in local AI integration and electronics projects.',
          },
          {
            heading: 'currently',
            text: 'Building Flutter applications and exploring Ollama for local LLM integration. Active in hackathons and open-source projects. Experimenting with 3D printing for electronics enclosures.',
          },
        ],
        interestsHeading: 'interests',
        interests: ['Flutter 🚀', 'Ollama/LLMs 🤖', 'Electronics ⚡', '3D-Printing 🖨️', 'Hackathons 🎯'],
      },
    },
    { // work
      id: 'work',
      desktopIcon: '💼',
      desktopLabel: 'work',
      titleIcon: '💼',
      titleText: 'work',
      frame: { width: 460, height: 500, top: 80, left: 200 },
      body: {
        type: 'work',
        heading: 'Projects',
        subheading: 'things i\'ve built',
        projects: [
          {
            emoji: '🐦',
            title: 'Project Raven',
            year: '2025',
            description: 'A comprehensive Flutter application featuring real-time data synchronization, offline-first architecture, and seamless cross-platform compatibility. Built with clean architecture principles.',
            tags: [
              { text: 'flutter', tone: 'accent' },
              { text: 'dart', tone: 'accent' },
              { text: 'mobile', tone: 'accent' },
            ],
          },
          {
            emoji: '📱',
            title: 'MobileOllama',
            year: '2026',
            description: 'Run local LLMs directly on your mobile device. A Flutter wrapper around Ollama enabling on-device AI inference with zero cloud dependencies.',
            tags: [
              { text: 'flutter', tone: 'accent2' },
              { text: 'ollama', tone: 'accent2' },
              { text: 'ai', tone: 'accent2' },
            ],
          },
          {
            emoji: '🧠',
            title: 'Obsidian Ollama Integration',
            year: '2025',
            description: 'Seamlessly integrate local Ollama LLMs into Obsidian for AI-powered note analysis, summaries, and intelligent linking. Fully privacy-preserving.',
            tags: [
              { text: 'javascript', tone: 'accent3' },
              { text: 'ollama', tone: 'accent3' },
              { text: 'plugin', tone: 'accent3' },
            ],
          },
          {
            emoji: '🖥️',
            title: 'ScriptHub',
            year: '2025',
            description: 'A Windows system-tray utility in C++ for launching and organizing scripts and workflows quickly from one place.',
            tags: [
              { text: 'c++', tone: 'accent4' },
              { text: 'windows', tone: 'accent4' },
              { text: 'system tray', tone: 'accent4' },
            ],
          },
          {
            emoji: '🗂️',
            title: 'simpleBackupWithGit',
            year: '2025',
            description: 'Python backup tool for selected file types with optional Git integration for versioned local or remote backups.',
            tags: [
              { text: 'python', tone: 'accent5' },
              { text: 'git', tone: 'accent5' },
              { text: 'automation', tone: 'accent5' },
            ],
          },
          {
            emoji: '💡',
            title: 'DIY-lamp',
            year: '2025',
            description: 'ESP32-based smart lamp project with web control, sensor input, and OLED output for a compact hardware + software build.',
            tags: [
              { text: 'esp32', tone: 'accent6' },
              { text: 'arduino', tone: 'accent6' },
              { text: 'iot', tone: 'accent6' },
            ],
          },
          {
            emoji: '🤖',
            title: 'simpleMind-AI',
            year: '2025',
            description: 'A self-built AI learning project trained on selected data to explore model behavior, inference, and text prediction basics.',
            tags: [
              { text: 'python', tone: 'accent8' },
              { text: 'ai', tone: 'accent8' },
              { text: 'ml experiment', tone: 'accent8' },
            ],
          },
          {
            emoji: '🏁',
            title: 'Hackathons',
            year: '2024-2025',
            description: 'A growing collection of hackathon experiments and rapid prototypes across different stacks and problem domains.',
            tags: [
              { text: 'python', tone: 'accent7' },
              { text: 'rapid prototyping', tone: 'accent7' },
              { text: 'team coding', tone: 'accent7' },
            ],
          },
        ],
        footerText: '+ more projects at github.com/Le0nyx 🚀',
      },
    },
    { // skills
      id: 'skills',
      desktopIcon: '⚡',
      desktopLabel: 'skills',
      titleIcon: '⚡',
      titleText: 'skills',
      frame: { width: 480, height: 520, top: 100, left: 520 },
      body: {
        type: 'skills',
        heading: 'Skills',
        subheading: 'stack from real projects',
        iconSkillsHeading: 'core stack',
        iconSkills: [
          { icon: 'flutter', label: 'Flutter', tone: 'accent' },
          { icon: 'js', label: 'JavaScript', tone: 'accent2' },
          { icon: 'py', label: 'Python', tone: 'accent3' },
          { icon: 'cpp', label: 'C++', tone: 'accent4' },
          { icon: 'c', label: 'C', tone: 'accent5' },
          { icon: 'cs', label: 'C#', tone: 'accent6' },
          { icon: 'java', label: 'Java', tone: 'accent7' },
          { icon: 'php', label: 'PHP', tone: 'accent8' },
          { icon: 'mysql', label: 'MySQL', tone: 'accent' },
          { icon: 'docker', label: 'Docker', tone: 'accent2' },
          { icon: 'linux', label: 'Linux', tone: 'accent3' },
          { icon: 'arduino', label: 'Arduino', tone: 'accent4' },
          { icon: 'raspberrypi', label: 'Raspberry Pi', tone: 'accent5' },
          { icon: 'unity', label: 'Unity', tone: 'accent6' },
        ],
        groups: [
          {
            heading: 'languages & frameworks',
            bars: [
              { name: 'Dart / Flutter', width: 92, delay: '0s' },
              { name: 'JavaScript / HTML / CSS', width: 65, delay: '0.1s' },
              { name: 'Python', width: 80, delay: '0.2s' },
              { name: 'C++', width: 60, delay: '0.3s' },
              { name: 'C / Embedded', width: 83, delay: '0.35s' },
              { name: 'SQL / MySQL', width: 75, delay: '0.4s' },
              { name: 'C# / Unity', width: 45, delay: '0.45s' },
              { name: 'Java', width: 69, delay: '0.5s' },
              { name: 'PHP', width: 55, delay: '0.55s' },
              { name: 'Ollama API', width: 78, delay: '0.6s' },
              { name: 'Docker', width: 68, delay: '0.65s' },
              
            ],
          },
          {
            heading: 'platforms & domains',
            bars: [
              { name: 'Android', width: 90, delay: '0.45s' },
              { name: 'Linux', width: 88, delay: '0.5s' },
              { name: 'Windows', width: 72, delay: '0.55s' },
              { name: 'Obsidian Plugins', width: 78, delay: '0.6s' },
              { name: 'Local AI / Ollama', width: 84, delay: '0.65s' },
              { name: 'IoT Prototyping', width: 96, delay: '0.7s' },
            ],
          },
        ],
        toolsHeading: 'tools',
        tools: [
          'Git',
          'GitHub Actions (basic)',
          'VS Code',
          'Flutter SDK',
          'Ollama API',
          'Arduino IDE',
          'Docker',
          'Linux CLI',
          'Windows system tooling',
          'JSON/API integration',
        ],
      },
    },
    { // q&a
      id: 'qa',
      desktopIcon: '❓',
      desktopLabel: 'q&a',
      titleIcon: '❓',
      titleText: 'q&a',
      frame: { width: 500, height: 520, top: 110, left: 340 },
      body: {
        type: 'qa',
        heading: 'Q&A',
        subheading: 'mostly genuine, a little fun',
        intro: '',
        items: [
          { question: 'What inspired you to start coding?', answer: 'It all started way back with Minecraft Pocket Edition and Command Blocks. In some way chaining Command Blocks and trying to create something has a big similarity to coding and so I continued and chose to study Computer Science later on.' },
          { question: 'What project are you proudest of right now?', answer: 'Currently I am most proud of Project Raven, since it took a lot of effort and time to create and its actually usefull on a daily basis.' },
          { question: 'Coffee or energy drinks?', answer: 'A mix of both. Some days I need the focus boost of an energy drink, other days I just want to enjoy a good cup of coffee.' },
          { question: 'What are you learning next?', answer: 'Next I am trying to dive deeper into low level programming with creating my own small OS.' },
          { question: 'What part of development do you find hardest?', answer: 'When there is a bug you can not seem to get rid of. At these points I most likely call it a day and go to sleep and just try the next day again or if it is a smaller project start sometimes from scratch.' },
          { question: 'What error message still lives rent-free in your head?', answer: 'Segmentation fault and you can not find where it is comming from.' },
        ],
        footerText: '',
      },
    },
    { // github
      id: 'github',
      desktopIcon: '🐈‍⬛',
      desktopLabel: 'github',
      titleIcon: '🐈‍⬛',
      titleText: 'github',
      frame: { width: 480, height: 320, top: 130, left: 360 },
      body: {
        type: 'github',
        heading: 'GitHub',
        subheading: 'follow my work',
        profileName: 'Le0nyx',
        profileUrl: PROFILE.githubUrl,
        avatarSrc: PROFILE.avatarUrl,
        avatarAlt: 'Le0nyx profile picture',
        footerText: 'opens in a new tab ↗',
      },
    },
  ],
};

// ---- State ----
let zTop = 100;
const taskbarWindows = {};
const windowStates = {}; // 'open' | 'minimized' | 'closed'

const windowsById = Object.fromEntries(PORTFOLIO_CONTENT.windows.map(w => [w.id, w]));
const windowMeta = Object.fromEntries(
  PORTFOLIO_CONTENT.windows.map(w => [
    w.id,
    { label: w.desktopLabel, icon: w.desktopIcon },
  ])
);
const desktopIconOrder = PORTFOLIO_CONTENT.windows.map(w => w.id);

function tagToneClass(tag) {
  return tag.tone ? ` ${tag.tone}` : '';
}

function renderTagList(tags) {
  return `<div class="tag-list">${tags
    .map(tag => `<span class="tag${tagToneClass(tag)}">${tag.text}</span>`)
    .join('')}</div>`;
}

function renderWindowBody(body) {
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
          `<div class="skill-icon-pill ${skill.tone || ''}"><img src="https://skillicons.dev/icons?i=${skill.icon}" alt="${skill.label} icon"><span>${skill.label}</span></div>`
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

  return '';
}

function renderWindows() {
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

function renderDesktopIcons() {
  const iconGrid = document.getElementById('icon-grid');
  if (!iconGrid) return;

  iconGrid.innerHTML = '';
  desktopIconOrder.forEach(id => {
    const meta = windowMeta[id];
    if (!meta) return;

    const icon = document.createElement('div');
    icon.className = 'desktop-icon';
    icon.innerHTML = `<div class="icon-emoji">${meta.icon}</div><div class="icon-label">${meta.label}</div>`;
    icon.addEventListener('click', () => openWindow(id));
    iconGrid.appendChild(icon);
  });
}

function renderDesktopMeta() {
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

renderDesktopMeta();
renderDesktopIcons();
renderWindows();

// Auto-open Skills and About Me windows on page load with staggered animation
window.addEventListener('load', () => {
  openWindow('skills');
  setTimeout(() => {
    openWindow('about');
    focusWindow('about'); // About Me window on top
  }, 600);
});

// ---- Open / close / minimize ----
function openWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;

  document.getElementById('hint').classList.add('gone');

  if (windowStates[id] === 'minimized') {
    win.classList.remove('minimized');
    windowStates[id] = 'open';
    focusWindow(id);
    updateTaskbar(id, 'open');
    return;
  }
  if (windowStates[id] === 'open') {
    focusWindow(id);
    return;
  }

  win.classList.remove('hidden');
  win.classList.add('window-opening');
  win.addEventListener('animationend', () => win.classList.remove('window-opening'), { once: true });
  windowStates[id] = 'open';
  focusWindow(id);
  addToTaskbar(id);
}

function closeWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;
  win.classList.add('hidden');
  windowStates[id] = 'closed';
  removeFromTaskbar(id);
}

function minimizeWindow(id) {
  const win = document.getElementById(id);
  if (!win) return;
  win.classList.add('minimized');
  windowStates[id] = 'minimized';
  updateTaskbar(id, 'minimized');
}

function maximizeWindow(id) {
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

// ---- Focus ----
function focusWindow(id) {
  document.querySelectorAll('.window').forEach(w => w.classList.remove('focused'));
  const win = document.getElementById(id);
  if (!win) return;

  win.style.zIndex = ++zTop;
  win.classList.add('focused');
  Object.keys(taskbarWindows).forEach(k => {
    if (taskbarWindows[k]) taskbarWindows[k].classList.toggle('active', k === id);
  });
}

// ---- Taskbar ----
const taskbarLeft = document.getElementById('taskbar-left');

function addToTaskbar(id) {
  if (taskbarWindows[id]) return;
  const meta = windowMeta[id] || { icon: '🗔', label: id };
  const btn = document.createElement('div');
  btn.className = 'taskbar-btn active';
  btn.innerHTML = `<span class="tb-icon">${meta.icon}</span><span class="tb-label">${meta.label}</span>`;
  btn.onclick = () => {
    if (windowStates[id] === 'minimized') {
      openWindow(id);
    } else if (document.getElementById(id)?.classList.contains('focused')) {
      minimizeWindow(id);
    } else {
      focusWindow(id);
    }
  };
  taskbarLeft.appendChild(btn);
  taskbarWindows[id] = btn;
  Object.keys(taskbarWindows).forEach(k => {
    if (taskbarWindows[k]) taskbarWindows[k].classList.toggle('active', k === id);
  });
}

function removeFromTaskbar(id) {
  if (taskbarWindows[id]) {
    taskbarWindows[id].remove();
    taskbarWindows[id] = null;
  }
}

function updateTaskbar(id, state) {
  if (!taskbarWindows[id]) return;
  taskbarWindows[id].classList.toggle('active', state === 'open');
}

// ---- Click to focus ----
document.querySelectorAll('.window').forEach(win => {
  win.addEventListener('mousedown', () => focusWindow(win.id));
});

// ---- Dragging ----
document.querySelectorAll('.titlebar').forEach(tb => {
  let dragging = false;
  let ox = 0;
  let oy = 0;
  const win = tb.parentElement;

  tb.addEventListener('mousedown', e => {
    if (e.target.classList.contains('wc')) return;
    if (win.dataset.maximized === 'true') return;
    dragging = true;
    const rect = win.getBoundingClientRect();
    ox = e.clientX - rect.left;
    oy = e.clientY - rect.top;
    focusWindow(win.id);
    e.preventDefault();
  });

  document.addEventListener('mousemove', e => {
    if (!dragging) return;
    const deskH = window.innerHeight - 52;
    let nx = e.clientX - ox;
    let ny = e.clientY - oy;
    nx = Math.max(-win.offsetWidth + 60, Math.min(window.innerWidth - 60, nx));
    ny = Math.max(0, Math.min(deskH - 40, ny));
    win.style.left = `${nx}px`;
    win.style.top = `${ny}px`;
  });

  document.addEventListener('mouseup', () => {
    dragging = false;
  });
});

// ---- Resize ----
document.querySelectorAll('.resize-handle').forEach(handle => {
  let resizing = false;
  let startX;
  let startY;
  let startW;
  let startH;
  const win = handle.parentElement;

  handle.addEventListener('mousedown', e => {
    resizing = true;
    startX = e.clientX;
    startY = e.clientY;
    startW = win.offsetWidth;
    startH = win.offsetHeight;
    e.preventDefault();
    e.stopPropagation();
  });

  document.addEventListener('mousemove', e => {
    if (!resizing) return;
    const nw = Math.max(280, startW + (e.clientX - startX));
    const nh = Math.max(180, startH + (e.clientY - startY));
    win.style.width = `${nw}px`;
    win.style.height = `${nh}px`;
  });

  document.addEventListener('mouseup', () => {
    resizing = false;
  });
});

// ---- Dark mode ----
const btn = document.getElementById('darkmode-btn');

function applyTheme(theme) {
  document.documentElement.setAttribute('data-theme', theme);
  if (btn) btn.textContent = theme === 'dark' ? '☀️' : '🌙';
}

const savedTheme = localStorage.getItem('theme');
applyTheme(savedTheme || 'dark');

function toggleDark() {
  const isDark = document.documentElement.getAttribute('data-theme') === 'dark';
  const nextTheme = isDark ? 'light' : 'dark';
  applyTheme(nextTheme);
  localStorage.setItem('theme', nextTheme);
}

// ---- Clock ----
function updateClock() {
  const now = new Date();
  const h = String(now.getHours()).padStart(2, '0');
  const m = String(now.getMinutes()).padStart(2, '0');
  document.getElementById('taskbar-clock').textContent = `${h}:${m}`;
}
updateClock();
setInterval(updateClock, 10000);

// ---- Toast ----
let toastTimer;
function showToast(msg) {
  const t = document.getElementById('toast');
  t.textContent = msg;
  t.classList.add('show');
  clearTimeout(toastTimer);
  toastTimer = setTimeout(() => t.classList.remove('show'), 2500);
}
