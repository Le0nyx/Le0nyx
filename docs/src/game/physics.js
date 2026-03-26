import { dinoState } from '../state.js';
import { DINO_JUMP_VELOCITY } from '../config.js';

export function dinoJump() {
  if (!dinoState.running || dinoState.gameOver || !dinoState.player.onGround) return;
  dinoState.player.onGround = false;
  dinoState.player.vy = DINO_JUMP_VELOCITY;
}

export function dinoRectsOverlap(a, b) {
  return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y;
}

export function getObstacleCollisionRect(obs) {
  if (obs.type === 'ptero') {
    return {
      x: obs.x + 7,
      y: obs.y + 8,
      w: obs.w - 14,
      h: obs.h - 14,
    };
  }

  return {
    x: obs.x + 2,
    y: obs.y + 4,
    w: obs.w - 4,
    h: obs.h - 6,
  };
}

export function checkCollisions() {
  if (dinoState.gameOver) return false;

  const playerRect = {
    x: dinoState.player.x + 4,
    y: dinoState.player.y + 2,
    w: dinoState.player.w - 8,
    h: dinoState.player.h - 4,
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

export function updatePlayerPhysics(baselineY, playerHeight, playerWidth, gravity, dtFactor) {
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
