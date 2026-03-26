import { dinoState, uiState } from '../state.js';
import { dinoJump } from './physics.js';
import { ensureDinoCanvasSize } from './utils.js';

export function isMobileViewport() {
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

export function initializeDinoInput(resetGameFn) {
  window.addEventListener('keydown', e => {
    if (uiState.windowStates.dino !== 'open' || isMobileViewport()) return;

    const key = e.key.toLowerCase();
    if ([' ', 'arrowup', 'w', 'arrowdown', 's', 'r'].includes(key)) {
      e.preventDefault();
    }

    if (key === ' ' || key === 'arrowup' || key === 'w') {
      dinoJump();
      return;
    }

    if (key === 'arrowdown' || key === 's') {
      dinoState.ducking = true;
      return;
    }

    if (key === 'r' && dinoState.gameOver) {
      resetGameFn();
      return;
    }
  });

  window.addEventListener('keyup', e => {
    if (uiState.windowStates.dino !== 'open' || isMobileViewport()) return;
    const key = e.key.toLowerCase();
    if (key === 'arrowdown' || key === 's') {
      dinoState.ducking = false;
    }
  });

  window.addEventListener('resize', () => {
    if (uiState.windowStates.dino === 'open' && !isMobileViewport()) {
      ensureDinoCanvasSize();
    }
  });
}
