"use strict";

import { PORTFOLIO_CONTENT } from './data/portfolio-data.js';
import { DESKTOP_ICON_ORDER } from './config.js';
import { renderDesktopMeta, renderDesktopIcons, renderWindows } from './ui/rendering.js';
import { openWindow, closeWindow, minimizeWindow, maximizeWindow, focusWindow } from './ui/windows.js';
import { initializeWindowInteractions, initializeTheme, toggleDarkMode } from './ui/interactions.js';
import { initializeClock, showToast } from './ui/utils.js';
import { startDinoGame, stopDinoGame, resetDinoGame } from './game/game.js';
import {
  startMinesweeperGame,
  stopMinesweeperGame,
  resetMinesweeperGame,
  setMinesweeperDifficulty,
  toggleMinesweeperFlagMode,
} from './game/minesweeper.js';
import { initializeDinoInput, isMobileViewport } from './game/input.js';

function initializeApplication() {
  const windowMeta = Object.fromEntries(
    PORTFOLIO_CONTENT.windows.map(w => [
      w.id,
      { label: w.desktopLabel, icon: w.desktopIcon },
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

window.addEventListener('load', () => {
  if (isMobileViewport()) return;

  openWindow('skills');
  setTimeout(() => {
    openWindow('about');
    focusWindow('about');
  }, 600);
});

initializeApplication();
