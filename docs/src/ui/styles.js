import { TASKBAR_HEIGHT } from '../config.js';

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

export function clampWindowToViewport(win) {
  const isMobile = isMobileViewport();
  if (!win || isMobile) return;

  const maxWidth = Math.max(320, window.innerWidth - 24);
  const maxHeight = Math.max(240, window.innerHeight - TASKBAR_HEIGHT - 24);

  const width = Math.min(win.offsetWidth, maxWidth);
  const height = Math.min(win.offsetHeight, maxHeight);

  win.style.width = `${width}px`;
  win.style.height = `${height}px`;

  const deskH = window.innerHeight - TASKBAR_HEIGHT;
  const currentLeft = parseFloat(win.style.left || '0') || 0;
  const currentTop = parseFloat(win.style.top || '0') || 0;
  const clampedLeft = Math.max(0, Math.min(window.innerWidth - width, currentLeft));
  const clampedTop = Math.max(0, Math.min(deskH - height, currentTop));

  win.style.left = `${clampedLeft}px`;
  win.style.top = `${clampedTop}px`;
}
