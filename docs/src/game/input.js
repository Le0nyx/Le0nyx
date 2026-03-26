import { dinoState, uiState } from '../state.js';
import { MOBILE_BREAKPOINT } from '../config.js';
import { dinoJump } from './physics.js';
import { ensureDinoCanvasSize } from './utils.js';

export function isMobileViewport() {
  return window.innerWidth <= MOBILE_BREAKPOINT;
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
