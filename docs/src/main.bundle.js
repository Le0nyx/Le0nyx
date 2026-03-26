"use strict";
(() => {
  // src/data/portfolio-data.js
  var PROFILE = {
    githubUrl: "https://github.com/Le0nyx",
    avatarUrl: "https://github.com/Le0nyx.png"
  };
  var PORTFOLIO_CONTENT = {
    desktop: {
      hintEmoji: "\u{1F446}",
      hintText: "click the icons to explore",
      labelText: "inspired by sharyap.com",
      labelHref: "https://www.sharyap.com"
    },
    windows: [
      {
        // about me
        id: "about",
        desktopIcon: "\u{1FAB4}",
        desktopLabel: "about me",
        titleIcon: "\u{1FAB4}",
        titleText: "about me",
        frame: { width: 520, height: 520, top: 60, left: 280 },
        body: {
          type: "about",
          avatarSrc: PROFILE.avatarUrl,
          avatarAlt: "Le0nyx profile picture",
          avatarEmoji: "\u2728",
          name: "Leon",
          subtitle: "student & developer",
          intro: "Hey! I'm a computer science student from northern Italy. I code in my freetime building apps and tinkering with electronics. Currently exploring Flutter, Ollama, and AI integration.",
          primaryTags: [
            { text: "flutter", tone: "accent" },
            { text: "fullstack", tone: "accent2" },
            { text: "ai/ollama", tone: "accent3" },
            { text: "3d-printing", tone: "accent4" },
            { text: "open source", tone: "accent5" },
            { text: "hackathons", tone: "accent6" },
            { text: "electronics", tone: "accent7" },
            { text: "coffee \u2615", tone: "accent8" }
          ],
          sections: [
            {
              heading: "background",
              text: "Passionate about creating solutions to complex problems. Started with web development and gradually moved into cross-platform mobile development with Flutter. Deeply interested in local AI integration and electronics projects."
            },
            {
              heading: "currently",
              text: "Building Flutter applications and exploring Ollama for local LLM integration. Active in hackathons and open-source projects. Experimenting with 3D printing for electronics enclosures."
            }
          ],
          interestsHeading: "interests",
          interests: ["Flutter \u{1F680}", "Ollama/LLMs \u{1F916}", "Electronics \u26A1", "3D-Printing \u{1F5A8}\uFE0F", "Hackathons \u{1F3AF}"]
        }
      },
      {
        // work
        id: "work",
        desktopIcon: "\u{1F4BC}",
        desktopLabel: "work",
        titleIcon: "\u{1F4BC}",
        titleText: "work",
        frame: { width: 460, height: 500, top: 80, left: 200 },
        body: {
          type: "work",
          heading: "Projects",
          subheading: "things i've built",
          projects: [
            {
              emoji: "\u{1F426}",
              title: "Project Raven",
              year: "2025",
              description: "A comprehensive Flutter application featuring real-time data synchronization, offline-first architecture, and seamless cross-platform compatibility. Built with clean architecture principles.",
              tags: [
                { text: "flutter", tone: "accent" },
                { text: "dart", tone: "accent" },
                { text: "mobile", tone: "accent" }
              ]
            },
            {
              emoji: "\u{1F4F1}",
              title: "MobileOllama",
              year: "2026",
              description: "Run local LLMs directly on your mobile device. A Flutter wrapper around Ollama enabling on-device AI inference with zero cloud dependencies.",
              tags: [
                { text: "flutter", tone: "accent2" },
                { text: "ollama", tone: "accent2" },
                { text: "ai", tone: "accent2" }
              ]
            },
            {
              emoji: "\u{1F9E0}",
              title: "Obsidian Ollama Integration",
              year: "2025",
              description: "Seamlessly integrate local Ollama LLMs into Obsidian for AI-powered note analysis, summaries, and intelligent linking. Fully privacy-preserving.",
              tags: [
                { text: "javascript", tone: "accent3" },
                { text: "ollama", tone: "accent3" },
                { text: "plugin", tone: "accent3" }
              ]
            },
            {
              emoji: "\u{1F5A5}\uFE0F",
              title: "ScriptHub",
              year: "2025",
              description: "A Windows system-tray utility in C++ for launching and organizing scripts and workflows quickly from one place.",
              tags: [
                { text: "c++", tone: "accent4" },
                { text: "windows", tone: "accent4" },
                { text: "system tray", tone: "accent4" }
              ]
            },
            {
              emoji: "\u{1F5C2}\uFE0F",
              title: "simpleBackupWithGit",
              year: "2025",
              description: "Python backup tool for selected file types with optional Git integration for versioned local or remote backups.",
              tags: [
                { text: "python", tone: "accent5" },
                { text: "git", tone: "accent5" },
                { text: "automation", tone: "accent5" }
              ]
            },
            {
              emoji: "\u{1F4A1}",
              title: "DIY-lamp",
              year: "2025",
              description: "ESP32-based smart lamp project with web control, sensor input, and OLED output for a compact hardware + software build.",
              tags: [
                { text: "esp32", tone: "accent6" },
                { text: "arduino", tone: "accent6" },
                { text: "iot", tone: "accent6" }
              ]
            },
            {
              emoji: "\u{1F916}",
              title: "simpleMind-AI",
              year: "2025",
              description: "A self-built AI learning project trained on selected data to explore model behavior, inference, and text prediction basics.",
              tags: [
                { text: "python", tone: "accent8" },
                { text: "ai", tone: "accent8" },
                { text: "ml experiment", tone: "accent8" }
              ]
            },
            {
              emoji: "\u{1F3C1}",
              title: "Hackathons",
              year: "2024-2025",
              description: "A growing collection of hackathon experiments and rapid prototypes across different stacks and problem domains.",
              tags: [
                { text: "python", tone: "accent7" },
                { text: "rapid prototyping", tone: "accent7" },
                { text: "team coding", tone: "accent7" }
              ]
            }
          ],
          footerText: "+ more projects at github.com/Le0nyx \u{1F680}"
        }
      },
      {
        // skills
        id: "skills",
        desktopIcon: "\u26A1",
        desktopLabel: "skills",
        titleIcon: "\u26A1",
        titleText: "skills",
        frame: { width: 480, height: 520, top: 100, left: 520 },
        body: {
          type: "skills",
          heading: "Skills",
          subheading: "stack from real projects",
          iconSkillsHeading: "core stack",
          iconSkills: [
            { icon: "flutter", label: "Flutter", tone: "accent" },
            { icon: "js", label: "JavaScript", tone: "accent2" },
            { icon: "py", label: "Python", tone: "accent3" },
            { icon: "cpp", label: "C++", tone: "accent4" },
            { icon: "c", label: "C", tone: "accent5" },
            { icon: "cs", label: "C#", tone: "accent6" },
            { icon: "java", label: "Java", tone: "accent7" },
            { icon: "php", label: "PHP", tone: "accent8" },
            { icon: "mysql", label: "MySQL", tone: "accent" },
            { icon: "docker", label: "Docker", tone: "accent2" },
            { icon: "linux", label: "Linux", tone: "accent3" },
            { icon: "arduino", label: "Arduino", tone: "accent4" },
            { icon: "raspberrypi", label: "Raspberry Pi", tone: "accent5" },
            { icon: "unity", label: "Unity", tone: "accent6" }
          ],
          groups: [
            {
              heading: "languages & frameworks",
              bars: [
                { name: "Dart / Flutter", width: 92, delay: "0s" },
                { name: "JavaScript / HTML / CSS", width: 65, delay: "0.1s" },
                { name: "Python", width: 80, delay: "0.2s" },
                { name: "C++", width: 60, delay: "0.3s" },
                { name: "C / Embedded", width: 83, delay: "0.35s" },
                { name: "SQL / MySQL", width: 75, delay: "0.4s" },
                { name: "C# / Unity", width: 45, delay: "0.45s" },
                { name: "Java", width: 69, delay: "0.5s" },
                { name: "PHP", width: 55, delay: "0.55s" },
                { name: "Ollama API", width: 78, delay: "0.6s" },
                { name: "Docker", width: 68, delay: "0.65s" }
              ]
            },
            {
              heading: "platforms & domains",
              bars: [
                { name: "Android", width: 90, delay: "0.45s" },
                { name: "Linux", width: 88, delay: "0.5s" },
                { name: "Windows", width: 72, delay: "0.55s" },
                { name: "Obsidian Plugins", width: 78, delay: "0.6s" },
                { name: "Local AI / Ollama", width: 84, delay: "0.65s" },
                { name: "IoT Prototyping", width: 96, delay: "0.7s" }
              ]
            }
          ],
          toolsHeading: "tools",
          tools: [
            "Git",
            "GitHub Actions (basic)",
            "VS Code",
            "Flutter SDK",
            "Ollama API",
            "Arduino IDE",
            "Docker",
            "Linux CLI",
            "Windows system tooling",
            "JSON/API integration"
          ]
        }
      },
      {
        // q&a
        id: "qa",
        desktopIcon: "\u2753",
        desktopLabel: "q&a",
        titleIcon: "\u2753",
        titleText: "q&a",
        frame: { width: 500, height: 520, top: 110, left: 340 },
        body: {
          type: "qa",
          heading: "Q&A",
          subheading: "mostly genuine, a little fun",
          intro: "",
          items: [
            { question: "What inspired you to start coding?", answer: "It all started way back with Minecraft Pocket Edition and Command Blocks. In some way chaining Command Blocks and trying to create something has a big similarity to coding and so I continued and chose to study Computer Science later on." },
            { question: "What project are you proudest of right now?", answer: "Currently I am most proud of Project Raven, since it took a lot of effort and time to create and its actually usefull on a daily basis." },
            { question: "Coffee or energy drinks?", answer: "A mix of both. Some days I need the focus boost of an energy drink, other days I just want to enjoy a good cup of coffee." },
            { question: "What are you learning next?", answer: "Next I am trying to dive deeper into low level programming with creating my own small OS." },
            { question: "What part of development do you find hardest?", answer: "When there is a bug you can not seem to get rid of. At these points I most likely call it a day and go to sleep and just try the next day again or if it is a smaller project start sometimes from scratch." },
            { question: "What error message still lives rent-free in your head?", answer: "Segmentation fault and you can not find where it is comming from." }
          ],
          footerText: ""
        }
      },
      {
        // github
        id: "github",
        desktopIcon: "\u{1F408}\u200D\u2B1B",
        desktopLabel: "github",
        titleIcon: "\u{1F408}\u200D\u2B1B",
        titleText: "github",
        frame: { width: 480, height: 320, top: 130, left: 360 },
        body: {
          type: "github",
          heading: "GitHub",
          subheading: "follow my work",
          profileName: "Le0nyx",
          profileUrl: PROFILE.githubUrl,
          avatarSrc: PROFILE.avatarUrl,
          avatarAlt: "Le0nyx profile picture",
          footerText: "opens in a new tab \u2197"
        }
      },
      {
        // dino
        id: "dino",
        desktopIcon: "\u{1F996}",
        desktopLabel: "dino",
        titleIcon: "\u{1F996}",
        titleText: "offline dino",
        frame: { width: 1240, height: 860, top: 18, left: 120 },
        body: {
          type: "dino",
          heading: "Offline Dino",
          subheading: "desktop arcade",
          mobileNote: "Sorry, this game is only available in desktop view."
        }
      },
      {
        // minesweeper
        id: "minesweeper",
        desktopIcon: "\u{1F4A3}",
        desktopLabel: "minesweeper",
        titleIcon: "\u{1F4A3}",
        titleText: "minesweeper",
        frame: { width: 980, height: 760, top: 24, left: 180 },
        body: {
          type: "minesweeper",
          heading: "Minesweeper",
          subheading: "classic board",
          mobileNote: "Sorry, this game is only available in desktop view."
        }
      }
    ]
  };

  // src/config.js
  var MOBILE_BREAKPOINT = 768;
  var TASKBAR_HEIGHT = 52;
  var DINO_SPRITE_URL = "assets/dino/100-offline-sprite.png";
  var DINO_GRAVITY = 1.02;
  var DINO_JUMP_VELOCITY = -18.6;
  var DINO_INITIAL_SPEED = 6.2;
  var DINO_MIN_SPAWN_GAP = 270;
  var PTERODACTYL_SPAWN_THRESHOLD = 8.6;
  var PTERODACTYL_SPAWN_SCORE_THRESHOLD = 110;
  var DESKTOP_ICON_ORDER = ["about", "work", "skills", "qa", "github", "__spacer__", "__spacer__", "dino", "minesweeper"];

  // src/ui/rendering.js
  function tagToneClass(tag) {
    return tag.tone ? ` ${tag.tone}` : "";
  }
  function renderTagList(tags) {
    return `<div class="tag-list">${tags.map((tag) => `<span class="tag${tagToneClass(tag)}">${tag.text}</span>`).join("")}</div>`;
  }
  function renderWindowBody(body) {
    if (body.type === "about") {
      const avatarContent = body.avatarSrc ? `<img class="avatar-img" src="${body.avatarSrc}" alt="${body.avatarAlt || "Profile picture"}">` : body.avatarEmoji;
      const sections = body.sections.map((section) => `<div class="win-h3">${section.heading}</div><div class="win-p">${section.text}</div>`).join("");
      const interests = renderTagList(body.interests.map((text) => ({ text })));
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
    if (body.type === "work") {
      const cards = body.projects.map((project) => `
        <div class="project-card">
          <div class="project-header">
            <div class="project-emoji">${project.emoji}</div>
            <div class="project-title">${project.title}</div>
            <div class="project-year">${project.year}</div>
          </div>
          <div class="project-body">
            <div class="project-desc">${project.description}</div>
            <div class="tag-list" style="margin-top:8px">${project.tags.map((tag) => `<span class="tag${tagToneClass(tag)}">${tag.text}</span>`).join("")}</div>
          </div>
        </div>
      `).join("");
      return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      ${cards}
      <hr class="win-divider">
      <div class="win-p" style="font-size:11px">${body.footerText}</div>
    `;
    }
    if (body.type === "skills") {
      const iconSkills = (body.iconSkills || []).map(
        (skill) => `<div class="skill-icon-pill ${skill.tone || ""}"><img src="assets/skills/${skill.icon}.svg" alt="${skill.label} icon"><span>${skill.label}</span></div>`
      ).join("");
      const groups = body.groups.map((group) => {
        const bars = group.bars.map(
          (bar) => `<div class="skill-bar-row"><span class="skill-name">${bar.name}</span><div class="skill-track"><div class="skill-fill" style="width:${bar.width}%;animation-delay:${bar.delay}"></div></div></div>`
        ).join("");
        return `<div class="win-h3">${group.heading}</div>${bars}`;
      }).join("");
      return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      <div class="win-h3">${body.iconSkillsHeading || "icon skills"}</div>
      <div class="skill-icon-grid">${iconSkills}</div>
      ${groups}
      <div class="win-h3">${body.toolsHeading}</div>
      ${renderTagList(body.tools.map((text) => ({ text })))}
    `;
    }
    if (body.type === "qa") {
      const items = (body.items || []).map((item, i) => {
        const answer = (item.answer || "").trim() || "your answer here...";
        return `
          <div class="qa-item">
            <div class="qa-q">${i + 1}. ${item.question}</div>
            <div class="qa-a">${answer}</div>
          </div>
        `;
      }).join("");
      return `
      <div class="win-h1">${body.heading}</div>
      <div class="win-h2">${body.subheading}</div>
      <div class="win-p">${body.intro}</div>
      <div class="qa-group">${items}</div>
      <hr class="win-divider">
      <div class="win-p" style="font-size:11px">${body.footerText}</div>
    `;
    }
    if (body.type === "github") {
      const avatarContent = body.avatarSrc ? `<img class="avatar-img" src="${body.avatarSrc}" alt="${body.avatarAlt || "GitHub profile picture"}">` : "\u{1F408}\u200D\u2B1B";
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
      ${body.stats ? `<div class="win-p">${body.stats}</div>` : ""}
      <hr class="win-divider">
      <div class="win-p" style="font-size:10px">${body.footerText}</div>
    `;
    }
    if (body.type === "dino") {
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
      <div class="dino-controls">jump: space / w / arrow up \xB7 duck: s / arrow down \xB7 restart: r</div>
    `;
    }
    if (body.type === "minesweeper") {
      return `
      <div id="minesweeper-root" class="ms-shell">
        <div class="dino-head">
          <div>
            <div class="win-h1">${body.heading}</div>
            <div class="win-h2">${body.subheading}</div>
          </div>
          <button class="ms-reset" id="ms-status" onclick="resetMinesweeperGame()" title="new game"><img class="ms-reset-icon" src="assets/minesweeper/face-idle.svg" alt="game status icon"><span class="ms-reset-label">restart game</span></button>
        </div>

        <div class="ms-mobile-note">${body.mobileNote || "Sorry, this game is only available in desktop view."}</div>

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
    return "";
  }
  function renderWindows() {
    const root = document.getElementById("windows-root");
    if (!root) return;
    root.innerHTML = PORTFOLIO_CONTENT.windows.map((windowConfig) => {
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
    }).join("");
  }
  function renderDesktopIcons(desktopIconOrder, windowMeta) {
    const iconGrid = document.getElementById("icon-grid");
    if (!iconGrid) return;
    iconGrid.innerHTML = "";
    desktopIconOrder.forEach((id) => {
      if (id === "__spacer__") {
        const spacer = document.createElement("div");
        spacer.className = "desktop-icon desktop-icon-spacer";
        spacer.setAttribute("aria-hidden", "true");
        iconGrid.appendChild(spacer);
        return;
      }
      const meta = windowMeta[id];
      if (!meta) return;
      const icon = document.createElement("div");
      icon.className = id === "dino" ? "desktop-icon desktop-icon-dino" : "desktop-icon";
      icon.innerHTML = `<div class="icon-emoji">${meta.icon}</div><div class="icon-label">${meta.label}</div>`;
      icon.addEventListener("click", () => window.openWindow(id));
      iconGrid.appendChild(icon);
    });
  }
  function renderDesktopMeta() {
    const hintEmoji = document.getElementById("hint-emoji");
    const hintText = document.getElementById("hint-text");
    const desktopLabel = document.getElementById("desktop-label");
    if (hintEmoji) hintEmoji.textContent = PORTFOLIO_CONTENT.desktop.hintEmoji;
    if (hintText) hintText.textContent = PORTFOLIO_CONTENT.desktop.hintText;
    if (desktopLabel) {
      desktopLabel.textContent = PORTFOLIO_CONTENT.desktop.labelText;
      desktopLabel.href = PORTFOLIO_CONTENT.desktop.labelHref;
    }
  }

  // src/state.js
  var uiState = {
    zTop: 100,
    taskbarWindows: {},
    windowStates: {}
    // 'open' | 'minimized' | 'closed'
  };
  var dinoState = {
    initialized: false,
    running: false,
    gameOver: false,
    ducking: false,
    score: 0,
    speed: DINO_INITIAL_SPEED,
    lastTime: 0,
    nextSpawn: 0,
    rafId: 0,
    obstacles: [],
    clouds: [],
    groundOffset: 0,
    runFrame: 0,
    runFrameTimer: 0,
    player: {
      x: 80,
      y: 0,
      w: 36,
      h: 56,
      vy: 0,
      onGround: true
    },
    minSpawnGap: DINO_MIN_SPAWN_GAP,
    sprite: {
      url: DINO_SPRITE_URL,
      image: null,
      loaded: false,
      failed: false,
      frames: {
        idle: { sx: 848, sy: 2, sw: 44, sh: 47 },
        run0: { sx: 936, sy: 2, sw: 44, sh: 47 },
        run1: { sx: 980, sy: 2, sw: 44, sh: 47 },
        crash: { sx: 1068, sy: 2, sw: 44, sh: 47 },
        duck0: { sx: 1111, sy: 19, sw: 59, sh: 30 },
        duck1: { sx: 1170, sy: 19, sw: 59, sh: 30 },
        cloud: { sx: 86, sy: 2, sw: 46, sh: 14 },
        horizon: { sx: 2, sy: 54, sw: 600, sh: 12 },
        cactusSmall: { sx: 228, sy: 2, sw: 17, sh: 35 },
        cactusLarge: { sx: 332, sy: 2, sw: 25, sh: 50 },
        ptero: { sx: 134, sy: 2, sw: 46, sh: 40 }
      }
    }
  };
  var minesweeperState = {
    initialized: false,
    bound: false,
    running: false,
    gameOver: false,
    won: false,
    flagMode: false,
    difficulty: "beginner",
    width: 9,
    height: 9,
    mines: 10,
    timer: 0,
    timerId: 0,
    firstRevealDone: false,
    board: [],
    revealedCount: 0,
    flagsPlaced: 0
  };

  // src/ui/styles.js
  function clampWindowToViewport(win) {
    const isMobile = window.innerWidth <= MOBILE_BREAKPOINT;
    if (!win || isMobile) return;
    const maxWidth = Math.max(320, window.innerWidth - 24);
    const maxHeight = Math.max(240, window.innerHeight - TASKBAR_HEIGHT - 24);
    const width = Math.min(win.offsetWidth, maxWidth);
    const height = Math.min(win.offsetHeight, maxHeight);
    win.style.width = `${width}px`;
    win.style.height = `${height}px`;
    const deskH = window.innerHeight - TASKBAR_HEIGHT;
    const currentLeft = parseFloat(win.style.left || "0") || 0;
    const currentTop = parseFloat(win.style.top || "0") || 0;
    const clampedLeft = Math.max(0, Math.min(window.innerWidth - width, currentLeft));
    const clampedTop = Math.max(0, Math.min(deskH - height, currentTop));
    win.style.left = `${clampedLeft}px`;
    win.style.top = `${clampedTop}px`;
  }

  // src/game/sprites.js
  function ensureDinoSpriteLoaded() {
    if (dinoState.sprite.loaded || dinoState.sprite.failed || dinoState.sprite.image) return;
    const img = new Image();
    img.onload = () => {
      dinoState.sprite.image = img;
      dinoState.sprite.loaded = true;
    };
    img.onerror = () => {
      dinoState.sprite.failed = true;
    };
    img.src = dinoState.sprite.url;
    dinoState.sprite.image = img;
  }
  function isSpriteReady() {
    return dinoState.sprite.loaded && !!dinoState.sprite.image;
  }

  // src/game/utils.js
  function getDinoElements() {
    return {
      canvas: document.getElementById("dino-canvas"),
      score: document.getElementById("dino-score"),
      stage: document.getElementById("dino-stage-wrap")
    };
  }
  function ensureDinoCanvasSize() {
    const { canvas, stage } = getDinoElements();
    if (!canvas || !stage) return null;
    const rect = stage.getBoundingClientRect();
    const width = Math.max(700, Math.floor(rect.width - 4));
    const height = Math.max(280, Math.floor(rect.height - 4));
    canvas.width = width;
    canvas.height = height;
    return { canvas, width, height };
  }
  function spawnObstacles(w, baselineY) {
    const canSpawnPtero = dinoState.speed >= PTERODACTYL_SPAWN_THRESHOLD && dinoState.score > PTERODACTYL_SPAWN_SCORE_THRESHOLD;
    const roll = Math.random();
    let obs;
    if (canSpawnPtero && roll < 0.28) {
      const lanes = [baselineY - 40, baselineY - 65, baselineY - 90];
      obs = {
        type: "ptero",
        x: w + 42,
        y: lanes[Math.floor(Math.random() * lanes.length)],
        w: 46,
        h: 40,
        size: 1,
        frame: 0,
        frameTimer: 0,
        frameRate: 166,
        speedOffset: 0.5 + Math.random() * 0.4
      };
    } else {
      const large = roll < 0.56;
      const baseW = large ? 25 : 17;
      const baseH = large ? 50 : 35;
      const maxGroup = large ? dinoState.speed >= 9.4 ? 2 : 1 : dinoState.speed >= 9.4 ? 3 : dinoState.speed >= 7.2 ? 2 : 1;
      const size = 1 + Math.floor(Math.random() * maxGroup);
      obs = {
        type: large ? "cactusLarge" : "cactusSmall",
        x: w + 42,
        y: baselineY - baseH,
        w: baseW * size,
        h: baseH,
        size,
        frame: 0,
        frameTimer: 0,
        frameRate: 0,
        speedOffset: 0
      };
    }
    const last = dinoState.obstacles[dinoState.obstacles.length - 1];
    const minGap = dinoState.minSpawnGap + dinoState.speed * 10 + (obs.type === "ptero" ? 70 : 0);
    const randomGap = 160 + Math.random() * 320;
    obs.x = last ? Math.max(w + 36, last.x + last.w + minGap + randomGap) : w + 40;
    dinoState.obstacles.push(obs);
    const nextMs = 420 + Math.random() * 380 - Math.min(180, dinoState.speed * 14);
    dinoState.nextSpawn = Math.max(210, nextMs);
  }
  function updateClouds(w, dt) {
    dinoState.clouds.forEach((cloud) => {
      if (!dinoState.gameOver) cloud.x -= dinoState.speed * 0.2 * (dt / 16.6667);
      if (cloud.x + cloud.w < -10) {
        cloud.x = w + 60 + Math.random() * 180;
        cloud.y = 36 + Math.random() * 92;
        cloud.w = 46;
      }
    });
  }
  function updateObstacles(dt) {
    dinoState.obstacles.forEach((obs) => {
      if (!dinoState.gameOver) {
        const actualSpeed = dinoState.speed + (obs.speedOffset || 0);
        obs.x -= Math.max(3, actualSpeed) * (dt / 16.6667);
        if (obs.type === "ptero") {
          obs.frameTimer += dt;
          if (obs.frameTimer >= obs.frameRate) {
            obs.frame = obs.frame ? 0 : 1;
            obs.frameTimer = 0;
          }
        }
      }
    });
    dinoState.obstacles = dinoState.obstacles.filter((obs) => obs.x + obs.w > -20);
  }
  function updateGameScore(dt) {
    if (!dinoState.gameOver) {
      dinoState.score += dt * 0.03;
      dinoState.speed += dt * 4e-4;
    }
  }
  function updateGroundOffset(dt) {
    if (!dinoState.gameOver) {
      dinoState.groundOffset = (dinoState.groundOffset + dinoState.speed * (dt / 16.6667)) % 600;
    }
  }

  // src/game/physics.js
  function dinoJump() {
    if (!dinoState.running || dinoState.gameOver || !dinoState.player.onGround) return;
    dinoState.player.onGround = false;
    dinoState.player.vy = DINO_JUMP_VELOCITY;
  }
  function dinoRectsOverlap(a, b) {
    return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y;
  }
  function getObstacleCollisionRect(obs) {
    if (obs.type === "ptero") {
      return {
        x: obs.x + 7,
        y: obs.y + 8,
        w: obs.w - 14,
        h: obs.h - 14
      };
    }
    return {
      x: obs.x + 2,
      y: obs.y + 4,
      w: obs.w - 4,
      h: obs.h - 6
    };
  }
  function checkCollisions() {
    if (dinoState.gameOver) return false;
    const playerRect = {
      x: dinoState.player.x + 4,
      y: dinoState.player.y + 2,
      w: dinoState.player.w - 8,
      h: dinoState.player.h - 4
    };
    for (const obs of dinoState.obstacles) {
      const obsRect = getObstacleCollisionRect(obs);
      if (dinoRectsOverlap(playerRect, obsRect)) {
        dinoState.gameOver = true;
        return true;
      }
    }
    return false;
  }
  function updatePlayerPhysics(baselineY, playerHeight, playerWidth, gravity, dtFactor) {
    dinoState.player.w = playerWidth;
    dinoState.player.h = playerHeight;
    if (dinoState.player.onGround) {
      dinoState.player.y = baselineY - playerHeight;
    }
    if (!dinoState.player.onGround) {
      dinoState.player.vy += gravity * dtFactor;
      dinoState.player.y += dinoState.player.vy * dtFactor;
      if (dinoState.player.y >= baselineY - playerHeight) {
        dinoState.player.y = baselineY - playerHeight;
        dinoState.player.vy = 0;
        dinoState.player.onGround = true;
      }
    }
  }

  // src/game/rendering.js
  function drawDinoCharacter(ctx, x, y, state) {
    const sprite = dinoState.sprite;
    if (!sprite.loaded || !sprite.image) {
      ctx.fillStyle = "#1e1e1e";
      ctx.fillRect(x + 10, y + 8, state.ducking ? 36 : 30, state.ducking ? 24 : 40);
      return;
    }
    let frame;
    if (state.gameOver) {
      frame = sprite.frames.crash;
    } else if (state.ducking) {
      frame = state.runFrame === 0 ? sprite.frames.duck0 : sprite.frames.duck1;
    } else if (state.runFrame === 0) {
      frame = sprite.frames.run0;
    } else {
      frame = sprite.frames.run1;
    }
    const drawW = state.ducking ? 58 : 46;
    const drawH = state.ducking ? 34 : 56;
    const drawY = state.ducking ? y + 2 : y - 1;
    ctx.drawImage(sprite.image, frame.sx, frame.sy, frame.sw, frame.sh, x, drawY, drawW, drawH);
  }
  function drawDinoObstacle(ctx, obs, spriteReady) {
    if (!spriteReady) {
      ctx.fillStyle = "#2d2d2d";
      ctx.fillRect(Math.floor(obs.x), Math.floor(obs.y), obs.w, obs.h);
      return;
    }
    const sprite = dinoState.sprite;
    if (obs.type === "ptero") {
      const src2 = sprite.frames.ptero;
      const sx = src2.sx + src2.sw * (obs.frame || 0);
      ctx.drawImage(sprite.image, sx, src2.sy, src2.sw, src2.sh, Math.floor(obs.x), Math.floor(obs.y), obs.w, obs.h);
      return;
    }
    const src = obs.type === "cactusLarge" ? sprite.frames.cactusLarge : sprite.frames.cactusSmall;
    const sourceX = src.sx + src.sw * obs.size * (0.5 * (obs.size - 1));
    ctx.drawImage(
      sprite.image,
      sourceX,
      src.sy,
      src.sw * obs.size,
      src.sh,
      Math.floor(obs.x),
      Math.floor(obs.y),
      obs.w,
      obs.h
    );
  }
  function drawDinoCloud(ctx, x, y, spriteReady) {
    if (!spriteReady) {
      ctx.fillStyle = "#d8d8d8";
      ctx.fillRect(Math.floor(x), Math.floor(y + 4), 36, 9);
      ctx.fillRect(Math.floor(x + 12), Math.floor(y), 16, 10);
      return;
    }
    const src = dinoState.sprite.frames.cloud;
    ctx.drawImage(dinoState.sprite.image, src.sx, src.sy, src.sw, src.sh, Math.floor(x), Math.floor(y), src.sw, src.sh);
  }
  function drawDinoHorizon(ctx, groundY, width, spriteReady) {
    if (!spriteReady) {
      ctx.fillStyle = "#444";
      ctx.fillRect(0, groundY + 6, width, 3);
      return;
    }
    const src = dinoState.sprite.frames.horizon;
    for (let x = -dinoState.groundOffset; x < width + src.sw; x += src.sw) {
      ctx.drawImage(
        dinoState.sprite.image,
        src.sx,
        src.sy,
        src.sw,
        src.sh,
        Math.floor(x),
        groundY + 6,
        src.sw,
        src.sh
      );
    }
  }

  // src/game/input.js
  function isMobileViewport() {
    return window.innerWidth <= MOBILE_BREAKPOINT;
  }
  function initializeDinoInput(resetGameFn) {
    window.addEventListener("keydown", (e) => {
      if (uiState.windowStates.dino !== "open" || isMobileViewport()) return;
      const key = e.key.toLowerCase();
      if ([" ", "arrowup", "w", "arrowdown", "s", "r"].includes(key)) {
        e.preventDefault();
      }
      if (key === " " || key === "arrowup" || key === "w") {
        dinoJump();
        return;
      }
      if (key === "arrowdown" || key === "s") {
        dinoState.ducking = true;
        return;
      }
      if (key === "r" && dinoState.gameOver) {
        resetGameFn();
        return;
      }
    });
    window.addEventListener("keyup", (e) => {
      if (uiState.windowStates.dino !== "open" || isMobileViewport()) return;
      const key = e.key.toLowerCase();
      if (key === "arrowdown" || key === "s") {
        dinoState.ducking = false;
      }
    });
    window.addEventListener("resize", () => {
      if (uiState.windowStates.dino === "open" && !isMobileViewport()) {
        ensureDinoCanvasSize();
      }
    });
  }

  // src/game/game.js
  function resetDinoGame() {
    dinoState.gameOver = false;
    dinoState.score = 0;
    dinoState.speed = DINO_INITIAL_SPEED;
    dinoState.obstacles = [];
    dinoState.lastTime = 0;
    dinoState.nextSpawn = 700;
    dinoState.ducking = false;
    dinoState.groundOffset = 0;
    dinoState.runFrame = 0;
    dinoState.runFrameTimer = 0;
    dinoState.player.vy = 0;
    dinoState.player.onGround = true;
    dinoState.player.y = 0;
    dinoState.clouds = Array.from({ length: 4 }, (_, i) => ({
      x: 180 + i * 290 + Math.random() * 90,
      y: 36 + Math.random() * 92,
      w: 46
    }));
  }
  function startDinoGame() {
    if (isMobileViewport()) return;
    ensureDinoSpriteLoaded();
    const sizeInfo = ensureDinoCanvasSize();
    if (!sizeInfo) return;
    if (!dinoState.initialized) {
      dinoState.initialized = true;
      resetDinoGame();
    }
    if (dinoState.running) return;
    dinoState.running = true;
    dinoState.lastTime = 0;
    dinoState.rafId = requestAnimationFrame(drawDinoFrame);
  }
  function stopDinoGame() {
    dinoState.running = false;
    if (dinoState.rafId) {
      cancelAnimationFrame(dinoState.rafId);
      dinoState.rafId = 0;
    }
  }
  function drawDinoFrame(timestamp) {
    const { canvas, score } = getDinoElements();
    if (!canvas) return;
    const ctx = canvas.getContext("2d");
    if (!ctx) return;
    ctx.imageSmoothingEnabled = false;
    if (!dinoState.lastTime) dinoState.lastTime = timestamp;
    const dt = Math.min(32, timestamp - dinoState.lastTime);
    const dtFactor = dt / 16.6667;
    dinoState.lastTime = timestamp;
    const w = canvas.width;
    const h = canvas.height;
    const groundY = h - 76;
    const baselineY = groundY + 19;
    const spriteReady = isSpriteReady();
    const playerHeight = dinoState.ducking ? 34 : 56;
    const playerWidth = dinoState.ducking ? 54 : 46;
    updatePlayerPhysics(baselineY, playerHeight, playerWidth, DINO_GRAVITY, dtFactor);
    if (!dinoState.gameOver) {
      updateGameScore(dt);
      dinoState.nextSpawn -= dt;
      if (dinoState.nextSpawn <= 0) {
        spawnObstacles(w, baselineY);
      }
    }
    updateClouds(w, dt);
    updateObstacles(dt);
    updateGroundOffset(dt);
    checkCollisions();
    ctx.clearRect(0, 0, w, h);
    ctx.fillStyle = "#fafafa";
    ctx.fillRect(0, 0, w, h);
    ctx.fillStyle = "#f3f3f3";
    ctx.fillRect(0, 0, w, Math.floor(h * 0.36));
    dinoState.clouds.forEach((cloud) => {
      drawDinoCloud(ctx, cloud.x, cloud.y, spriteReady);
    });
    drawDinoHorizon(ctx, groundY, w, spriteReady);
    if (!dinoState.gameOver && !dinoState.ducking) {
      dinoState.runFrameTimer += dt;
      if (dinoState.runFrameTimer >= 95) {
        dinoState.runFrame = dinoState.runFrame ? 0 : 1;
        dinoState.runFrameTimer = 0;
      }
    }
    drawDinoCharacter(ctx, dinoState.player.x, dinoState.player.y, {
      ducking: dinoState.ducking,
      gameOver: dinoState.gameOver,
      runFrame: dinoState.runFrame
    });
    dinoState.obstacles.forEach((obs) => {
      drawDinoObstacle(ctx, obs, spriteReady);
    });
    if (score) {
      score.textContent = `score: ${Math.floor(dinoState.score)}`;
    }
    if (dinoState.gameOver) {
      ctx.fillStyle = "rgba(20,20,20,0.7)";
      ctx.fillRect(0, 0, w, h);
      ctx.fillStyle = "#fff";
      ctx.font = "700 36px Syne, sans-serif";
      ctx.textAlign = "center";
      ctx.fillText("Game Over", w / 2, h / 2 - 10);
      ctx.font = "500 16px DM Mono, monospace";
      ctx.fillText("Press R to restart", w / 2, h / 2 + 28);
    }
    if (dinoState.running) {
      dinoState.rafId = requestAnimationFrame(drawDinoFrame);
    }
  }

  // src/game/minesweeper.js
  var PRESETS = {
    beginner: { width: 9, height: 9, mines: 10, label: "beginner" },
    intermediate: { width: 16, height: 16, mines: 40, label: "intermediate" },
    expert: { width: 30, height: 16, mines: 99, label: "expert" }
  };
  var MS_ASSETS = {
    mine: "assets/minesweeper/mine.svg",
    flag: "assets/minesweeper/flag.svg",
    faceIdle: "assets/minesweeper/face-idle.svg",
    faceWin: "assets/minesweeper/face-win.svg",
    faceBoom: "assets/minesweeper/face-boom.svg"
  };
  function isMobileViewport2() {
    return window.innerWidth <= MOBILE_BREAKPOINT;
  }
  function getUi() {
    return {
      root: document.getElementById("minesweeper-root"),
      board: document.getElementById("ms-board"),
      minesLeft: document.getElementById("ms-mines-left"),
      timer: document.getElementById("ms-timer"),
      status: document.getElementById("ms-status"),
      flagModeBtn: document.getElementById("ms-flag-mode-btn"),
      difficultyValue: document.getElementById("ms-difficulty-value")
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
      exploded: false
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
    }, 1e3);
  }
  function withPreset(name) {
    const preset = PRESETS[name] || PRESETS.beginner;
    minesweeperState.difficulty = name in PRESETS ? name : "beginner";
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
    const safe = /* @__PURE__ */ new Set([boardIndex(firstX, firstY)]);
    neighbors(firstX, firstY).forEach(([nx, ny]) => safe.add(boardIndex(nx, ny)));
    const mines = randomMinePositions(safe);
    mines.forEach((index) => {
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
    const prefix = value < 0 ? "-" : "";
    return `${prefix}${String(abs).padStart(3, "0")}`;
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
      ui.flagModeBtn.classList.toggle("active", minesweeperState.flagMode);
      ui.flagModeBtn.setAttribute("aria-pressed", minesweeperState.flagMode ? "true" : "false");
    }
    if (ui.difficultyValue) {
      const label = PRESETS[minesweeperState.difficulty]?.label || "beginner";
      ui.difficultyValue.textContent = label;
    }
    document.querySelectorAll(".ms-difficulty-btn").forEach((btn) => {
      const active = btn.textContent?.trim() === minesweeperState.difficulty;
      btn.classList.toggle("active", active);
    });
  }
  function revealAllMines() {
    minesweeperState.board.forEach((cell) => {
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
    const classes = ["ms-cell"];
    if (cell.revealed) classes.push("revealed");
    if (cell.flagged && !cell.revealed) classes.push("flagged");
    if (cell.mine && cell.revealed) classes.push("mine");
    if (cell.exploded) classes.push("exploded");
    let inner = "";
    if (cell.flagged && !cell.revealed) {
      inner = `<img class="ms-cell-icon" src="${MS_ASSETS.flag}" alt="flag">`;
    } else if (cell.revealed && cell.mine) {
      inner = `<img class="ms-cell-icon" src="${MS_ASSETS.mine}" alt="mine">`;
    } else if (cell.revealed && cell.adjacent > 0) {
      inner = `<span class="ms-num ms-num-${cell.adjacent}">${cell.adjacent}</span>`;
    }
    return `<button class="${classes.join(" ")}" data-role="cell" data-x="${x}" data-y="${y}" aria-label="cell ${x + 1},${y + 1}">${inner}</button>`;
  }
  function getCellSizePx() {
    if (minesweeperState.difficulty === "expert") return 20;
    if (minesweeperState.difficulty === "intermediate") return 24;
    return 28;
  }
  function renderBoard() {
    const ui = getUi();
    if (!ui.board || !ui.root) return;
    ui.root.style.setProperty("--ms-cell-size", `${getCellSizePx()}px`);
    ui.board.style.gridTemplateColumns = `repeat(${minesweeperState.width}, var(--ms-cell-size))`;
    let html = "";
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
    const x = Number(cell.getAttribute("data-x"));
    const y = Number(cell.getAttribute("data-y"));
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
    ui.board.addEventListener("click", onBoardClick);
    ui.board.addEventListener("contextmenu", onBoardContextMenu);
    ui.board.addEventListener("dblclick", onBoardDoubleClick);
    minesweeperState.bound = true;
  }
  function toggleMinesweeperFlagMode() {
    minesweeperState.flagMode = !minesweeperState.flagMode;
    syncHud();
  }
  function setMinesweeperDifficulty(name) {
    withPreset(name);
    newGame();
  }
  function resetMinesweeperGame() {
    newGame();
  }
  function startMinesweeperGame() {
    if (isMobileViewport2()) {
      stopMinesweeperGame();
      return;
    }
    const ui = getUi();
    if (!ui.root || !ui.board) return;
    if (!minesweeperState.initialized) {
      bindBoardEvents();
      minesweeperState.initialized = true;
      withPreset(minesweeperState.difficulty || "beginner");
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
  function stopMinesweeperGame() {
    minesweeperState.running = false;
    stopTimer();
  }

  // src/ui/windows.js
  function isMobileViewport3() {
    return window.innerWidth <= MOBILE_BREAKPOINT;
  }
  function focusWindow(id) {
    document.querySelectorAll(".window").forEach((w) => w.classList.remove("focused"));
    const win = document.getElementById(id);
    if (!win) return;
    win.style.zIndex = ++uiState.zTop;
    win.classList.add("focused");
    Object.keys(uiState.taskbarWindows).forEach((k) => {
      if (uiState.taskbarWindows[k]) uiState.taskbarWindows[k].classList.toggle("active", k === id);
    });
  }
  function openWindow(id) {
    const win = document.getElementById(id);
    if (!win) return;
    document.getElementById("hint").classList.add("gone");
    if (uiState.windowStates[id] === "minimized") {
      win.classList.remove("minimized");
      uiState.windowStates[id] = "open";
      focusWindow(id);
      updateTaskbar(id, "open");
      if (id === "dino") startDinoGame();
      if (id === "minesweeper") startMinesweeperGame();
      return;
    }
    if (uiState.windowStates[id] === "open") {
      focusWindow(id);
      if (id === "dino") startDinoGame();
      if (id === "minesweeper") startMinesweeperGame();
      return;
    }
    if (id === "dino" && !isMobileViewport3()) {
      const width = Math.floor(window.innerWidth * 0.78);
      const height = Math.floor((window.innerHeight - TASKBAR_HEIGHT) * 0.72);
      const finalW = Math.min(1180, Math.max(860, width));
      const finalH = Math.min(680, Math.max(540, height));
      win.style.width = `${finalW}px`;
      win.style.height = `${finalH}px`;
      win.style.left = `${Math.max(0, Math.floor((window.innerWidth - finalW) / 2))}px`;
      win.style.top = `${Math.max(8, Math.floor((window.innerHeight - TASKBAR_HEIGHT - finalH) / 2))}px`;
    }
    win.classList.remove("hidden");
    win.classList.add("window-opening");
    win.addEventListener("animationend", () => win.classList.remove("window-opening"), { once: true });
    clampWindowToViewport(win);
    uiState.windowStates[id] = "open";
    focusWindow(id);
    addToTaskbar(id);
    if (id === "dino") startDinoGame();
    if (id === "minesweeper") startMinesweeperGame();
  }
  function closeWindow(id) {
    const win = document.getElementById(id);
    if (!win) return;
    win.classList.add("hidden");
    uiState.windowStates[id] = "closed";
    removeFromTaskbar(id);
    if (id === "dino") stopDinoGame();
    if (id === "minesweeper") {
      stopMinesweeperGame();
      resetMinesweeperGame();
    }
  }
  function minimizeWindow(id) {
    const win = document.getElementById(id);
    if (!win) return;
    win.classList.add("minimized");
    uiState.windowStates[id] = "minimized";
    updateTaskbar(id, "minimized");
    if (id === "dino") stopDinoGame();
    if (id === "minesweeper") stopMinesweeperGame();
  }
  function maximizeWindow(id) {
    const win = document.getElementById(id);
    if (!win) return;
    const isMax = win.dataset.maximized === "true";
    if (!isMax) {
      win.dataset.prevStyle = `left:${win.style.left};top:${win.style.top};width:${win.style.width};height:${win.style.height}`;
      win.style.left = "0px";
      win.style.top = "0px";
      win.style.width = "calc(100vw)";
      win.style.height = "calc(100vh - 52px)";
      win.dataset.maximized = "true";
    } else {
      const prev = win.dataset.prevStyle;
      if (prev) {
        prev.split(";").forEach((s) => {
          const [k, v] = s.split(":");
          if (k && v) win.style[k.trim()] = v.trim();
        });
      }
      win.dataset.maximized = "false";
    }
  }
  function addToTaskbar(id) {
    if (uiState.taskbarWindows[id]) return;
    const taskbarLeft = document.getElementById("taskbar-left");
    const meta = window.windowMeta[id] || { icon: "\u{1F5D4}", label: id };
    const btn = document.createElement("div");
    btn.className = "taskbar-btn active";
    btn.innerHTML = `<span class="tb-icon">${meta.icon}</span><span class="tb-label">${meta.label}</span>`;
    btn.onclick = () => {
      if (uiState.windowStates[id] === "minimized") {
        openWindow(id);
      } else if (document.getElementById(id)?.classList.contains("focused")) {
        minimizeWindow(id);
      } else {
        focusWindow(id);
      }
    };
    taskbarLeft.appendChild(btn);
    uiState.taskbarWindows[id] = btn;
    Object.keys(uiState.taskbarWindows).forEach((k) => {
      if (uiState.taskbarWindows[k]) uiState.taskbarWindows[k].classList.toggle("active", k === id);
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
    uiState.taskbarWindows[id].classList.toggle("active", state === "open");
  }

  // src/ui/interactions.js
  function isMobileViewport4() {
    return window.innerWidth <= MOBILE_BREAKPOINT;
  }
  function initializeWindowInteractions() {
    document.querySelectorAll(".window").forEach((win) => {
      win.addEventListener("mousedown", () => focusWindow(win.id));
    });
    document.querySelectorAll(".titlebar").forEach((tb) => {
      let dragging = false;
      let ox = 0;
      let oy = 0;
      const win = tb.parentElement;
      tb.addEventListener("mousedown", (e) => {
        if (isMobileViewport4()) return;
        if (e.target.classList.contains("wc")) return;
        if (win.dataset.maximized === "true") return;
        dragging = true;
        const rect = win.getBoundingClientRect();
        ox = e.clientX - rect.left;
        oy = e.clientY - rect.top;
        focusWindow(win.id);
        e.preventDefault();
      });
      document.addEventListener("mousemove", (e) => {
        if (!dragging) return;
        const deskH = window.innerHeight - TASKBAR_HEIGHT;
        let nx = e.clientX - ox;
        let ny = e.clientY - oy;
        nx = Math.max(-win.offsetWidth + 60, Math.min(window.innerWidth - 60, nx));
        ny = Math.max(0, Math.min(deskH - 40, ny));
        win.style.left = `${nx}px`;
        win.style.top = `${ny}px`;
      });
      document.addEventListener("mouseup", () => {
        dragging = false;
      });
    });
    document.querySelectorAll(".resize-handle").forEach((handle) => {
      let resizing = false;
      let startX;
      let startY;
      let startW;
      let startH;
      const win = handle.parentElement;
      handle.addEventListener("mousedown", (e) => {
        if (isMobileViewport4()) return;
        resizing = true;
        startX = e.clientX;
        startY = e.clientY;
        startW = win.offsetWidth;
        startH = win.offsetHeight;
        e.preventDefault();
        e.stopPropagation();
      });
      document.addEventListener("mousemove", (e) => {
        if (!resizing) return;
        const nw = Math.max(280, startW + (e.clientX - startX));
        const nh = Math.max(180, startH + (e.clientY - startY));
        win.style.width = `${nw}px`;
        win.style.height = `${nh}px`;
      });
      document.addEventListener("mouseup", () => {
        resizing = false;
      });
    });
    window.addEventListener("resize", () => {
      if (isMobileViewport4()) return;
      document.querySelectorAll(".window").forEach((win) => {
        if (!win.classList.contains("hidden") && !win.classList.contains("minimized")) {
          clampWindowToViewport(win);
        }
      });
    });
  }
  function applyTheme(theme) {
    document.documentElement.setAttribute("data-theme", theme);
    const btn = document.getElementById("darkmode-btn");
    if (btn) btn.textContent = theme === "dark" ? "\u2600\uFE0F" : "\u{1F319}";
  }
  function toggleDarkMode() {
    const isDark = document.documentElement.getAttribute("data-theme") === "dark";
    const nextTheme = isDark ? "light" : "dark";
    applyTheme(nextTheme);
    localStorage.setItem("theme", nextTheme);
  }
  function initializeTheme() {
    const savedTheme = localStorage.getItem("theme");
    applyTheme(savedTheme || "dark");
  }

  // src/ui/utils.js
  var toastTimer;
  function showToast(msg) {
    const t = document.getElementById("toast");
    t.textContent = msg;
    t.classList.add("show");
    clearTimeout(toastTimer);
    toastTimer = setTimeout(() => t.classList.remove("show"), 2500);
  }
  function initializeClock() {
    function updateClock() {
      const now = /* @__PURE__ */ new Date();
      const h = String(now.getHours()).padStart(2, "0");
      const m = String(now.getMinutes()).padStart(2, "0");
      document.getElementById("taskbar-clock").textContent = `${h}:${m}`;
    }
    updateClock();
    setInterval(updateClock, 1e4);
  }

  // src/main.js
  function initializeApplication() {
    const windowMeta = Object.fromEntries(
      PORTFOLIO_CONTENT.windows.map((w) => [
        w.id,
        { label: w.desktopLabel, icon: w.desktopIcon }
      ])
    );
    window.openWindow = openWindow;
    window.closeWindow = closeWindow;
    window.minimizeWindow = minimizeWindow;
    window.maximizeWindow = maximizeWindow;
    window.focusWindow = focusWindow;
    window.toggleDark = toggleDarkMode;
    window.showToast = showToast;
    window.windowMeta = windowMeta;
    window.startDinoGame = startDinoGame;
    window.stopDinoGame = stopDinoGame;
    window.resetDinoGame = resetDinoGame;
    window.startMinesweeperGame = startMinesweeperGame;
    window.stopMinesweeperGame = stopMinesweeperGame;
    window.resetMinesweeperGame = resetMinesweeperGame;
    window.setMinesweeperDifficulty = setMinesweeperDifficulty;
    window.toggleMinesweeperFlagMode = toggleMinesweeperFlagMode;
    renderDesktopMeta();
    renderDesktopIcons(DESKTOP_ICON_ORDER, windowMeta);
    renderWindows();
    initializeWindowInteractions();
    initializeTheme();
    initializeClock();
    initializeDinoInput(resetDinoGame);
  }
  window.addEventListener("load", () => {
    if (isMobileViewport()) return;
    openWindow("skills");
    setTimeout(() => {
      openWindow("about");
      focusWindow("about");
    }, 600);
  });
  initializeApplication();
})();
