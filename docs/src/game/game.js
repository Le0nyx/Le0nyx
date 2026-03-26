import { dinoState, uiState } from '../state.js';
import { DINO_INITIAL_SPEED, DINO_GRAVITY } from '../config.js';
import { ensureDinoSpriteLoaded, isSpriteReady } from './sprites.js';
import {
  getDinoElements,
  ensureDinoCanvasSize,
  spawnObstacles,
  updateClouds,
  updateObstacles,
  updateGameScore,
  updateGroundOffset,
} from './utils.js';
import { updatePlayerPhysics, checkCollisions } from './physics.js';
import { drawDinoCharacter, drawDinoObstacle, drawDinoCloud, drawDinoHorizon } from './rendering.js';
import { isMobileViewport } from './input.js';

export function resetDinoGame() {
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
    w: 46,
  }));
}

export function startDinoGame() {
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

export function stopDinoGame() {
  dinoState.running = false;
  if (dinoState.rafId) {
    cancelAnimationFrame(dinoState.rafId);
    dinoState.rafId = 0;
  }
}

export function drawDinoFrame(timestamp) {
  const { canvas, score } = getDinoElements();
  if (!canvas) return;
  const ctx = canvas.getContext('2d');
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

  // Update physics
  updatePlayerPhysics(baselineY, playerHeight, playerWidth, DINO_GRAVITY, dtFactor);

  // Update game state
  if (!dinoState.gameOver) {
    updateGameScore(dt);
    dinoState.nextSpawn -= dt;
    if (dinoState.nextSpawn <= 0) {
      spawnObstacles(w, baselineY);
    }
  }

  // Update clouds and obstacles
  updateClouds(w, dt);
  updateObstacles(dt);
  updateGroundOffset(dt);

  // Check collisions
  checkCollisions();

  // Render
  ctx.clearRect(0, 0, w, h);

  ctx.fillStyle = '#fafafa';
  ctx.fillRect(0, 0, w, h);

  ctx.fillStyle = '#f3f3f3';
  ctx.fillRect(0, 0, w, Math.floor(h * 0.36));

  dinoState.clouds.forEach(cloud => {
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
    runFrame: dinoState.runFrame,
  });

  dinoState.obstacles.forEach(obs => {
    drawDinoObstacle(ctx, obs, spriteReady);
  });

  if (score) {
    score.textContent = `score: ${Math.floor(dinoState.score)}`;
  }

  if (dinoState.gameOver) {
    ctx.fillStyle = 'rgba(20,20,20,0.7)';
    ctx.fillRect(0, 0, w, h);
    ctx.fillStyle = '#fff';
    ctx.font = '700 36px Syne, sans-serif';
    ctx.textAlign = 'center';
    ctx.fillText('Game Over', w / 2, h / 2 - 10);
    ctx.font = '500 16px DM Mono, monospace';
    ctx.fillText('Press R to restart', w / 2, h / 2 + 28);
  }

  if (dinoState.running) {
    dinoState.rafId = requestAnimationFrame(drawDinoFrame);
  }
}
