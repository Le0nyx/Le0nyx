import { dinoState } from '../state.js';
import { PTERODACTYL_SPAWN_THRESHOLD, PTERODACTYL_SPAWN_SCORE_THRESHOLD } from '../config.js';

export function getDinoElements() {
  return {
    canvas: document.getElementById('dino-canvas'),
    score: document.getElementById('dino-score'),
    stage: document.getElementById('dino-stage-wrap'),
  };
}

export function ensureDinoCanvasSize() {
  const { canvas, stage } = getDinoElements();
  if (!canvas || !stage) return null;
  const rect = stage.getBoundingClientRect();
  const width = Math.max(700, Math.floor(rect.width - 4));
  const height = Math.max(280, Math.floor(rect.height - 4));
  canvas.width = width;
  canvas.height = height;
  return { canvas, width, height };
}

export function spawnObstacles(w, baselineY) {
  const canSpawnPtero = dinoState.speed >= PTERODACTYL_SPAWN_THRESHOLD && dinoState.score > PTERODACTYL_SPAWN_SCORE_THRESHOLD;
  const roll = Math.random();
  let obs;

  if (canSpawnPtero && roll < 0.28) {
    const lanes = [baselineY - 40, baselineY - 65, baselineY - 90];
    obs = {
      type: 'ptero',
      x: w + 42,
      y: lanes[Math.floor(Math.random() * lanes.length)],
      w: 46,
      h: 40,
      size: 1,
      frame: 0,
      frameTimer: 0,
      frameRate: 166,
      speedOffset: 0.5 + Math.random() * 0.4,
    };
  } else {
    const large = roll < 0.56;
    const baseW = large ? 25 : 17;
    const baseH = large ? 50 : 35;
    const maxGroup = large
      ? dinoState.speed >= 9.4
        ? 2
        : 1
      : dinoState.speed >= 9.4
        ? 3
        : dinoState.speed >= 7.2
          ? 2
          : 1;
    const size = 1 + Math.floor(Math.random() * maxGroup);
    obs = {
      type: large ? 'cactusLarge' : 'cactusSmall',
      x: w + 42,
      y: baselineY - baseH,
      w: baseW * size,
      h: baseH,
      size,
      frame: 0,
      frameTimer: 0,
      frameRate: 0,
      speedOffset: 0,
    };
  }

  const last = dinoState.obstacles[dinoState.obstacles.length - 1];
  const minGap = dinoState.minSpawnGap + dinoState.speed * 10 + (obs.type === 'ptero' ? 70 : 0);
  const randomGap = 160 + Math.random() * 320;
  obs.x = last ? Math.max(w + 36, last.x + last.w + minGap + randomGap) : w + 40;
  dinoState.obstacles.push(obs);

  const nextMs = 420 + Math.random() * 380 - Math.min(180, dinoState.speed * 14);
  dinoState.nextSpawn = Math.max(210, nextMs);
}

export function updateClouds(w, dt) {
  dinoState.clouds.forEach(cloud => {
    if (!dinoState.gameOver) cloud.x -= dinoState.speed * 0.2 * (dt / 16.6667);
    if (cloud.x + cloud.w < -10) {
      cloud.x = w + 60 + Math.random() * 180;
      cloud.y = 36 + Math.random() * 92;
      cloud.w = 46;
    }
  });
}

export function updateObstacles(dt) {
  dinoState.obstacles.forEach(obs => {
    if (!dinoState.gameOver) {
      const actualSpeed = dinoState.speed + (obs.speedOffset || 0);
      obs.x -= Math.max(3, actualSpeed) * (dt / 16.6667);
      if (obs.type === 'ptero') {
        obs.frameTimer += dt;
        if (obs.frameTimer >= obs.frameRate) {
          obs.frame = obs.frame ? 0 : 1;
          obs.frameTimer = 0;
        }
      }
    }
  });
  dinoState.obstacles = dinoState.obstacles.filter(obs => obs.x + obs.w > -20);
}

export function updateGameScore(dt) {
  if (!dinoState.gameOver) {
    dinoState.score += dt * 0.03;
    dinoState.speed += dt * 0.0004;
  }
}

export function updateGroundOffset(dt) {
  if (!dinoState.gameOver) {
    dinoState.groundOffset = (dinoState.groundOffset + dinoState.speed * (dt / 16.6667)) % 600;
  }
}
