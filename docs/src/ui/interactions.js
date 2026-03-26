import { TASKBAR_HEIGHT } from '../config.js';
import { clampWindowToViewport } from './styles.js';
import { focusWindow } from './windows.js';

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

export function initializeWindowInteractions() {
  // Click to focus
  document.querySelectorAll('.window').forEach(win => {
    win.addEventListener('mousedown', () => focusWindow(win.id));
  });

  // Dragging
  document.querySelectorAll('.titlebar').forEach(tb => {
    let dragging = false;
    let ox = 0;
    let oy = 0;
    const win = tb.parentElement;

    tb.addEventListener('mousedown', e => {
      if (isMobileViewport()) return;
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
      const deskH = window.innerHeight - TASKBAR_HEIGHT;
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

  // Resizing
  document.querySelectorAll('.resize-handle').forEach(handle => {
    let resizing = false;
    let startX;
    let startY;
    let startW;
    let startH;
    const win = handle.parentElement;

    handle.addEventListener('mousedown', e => {
      if (isMobileViewport()) return;
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

  // Window resize handler
  window.addEventListener('resize', () => {
    if (isMobileViewport()) return;
    document.querySelectorAll('.window').forEach(win => {
      if (!win.classList.contains('hidden') && !win.classList.contains('minimized')) {
        clampWindowToViewport(win);
      }
    });
  });
}

export function applyTheme(theme) {
  document.documentElement.setAttribute('data-theme', theme);
  const btn = document.getElementById('darkmode-btn');
  if (btn) btn.textContent = theme === 'dark' ? '☀️' : '🌙';
}

export function toggleDarkMode() {
  const isDark = document.documentElement.getAttribute('data-theme') === 'dark';
  const nextTheme = isDark ? 'light' : 'dark';
  applyTheme(nextTheme);
  localStorage.setItem('theme', nextTheme);
}

export function initializeTheme() {
  const savedTheme = localStorage.getItem('theme');
  applyTheme(savedTheme || 'dark');
}
