import { dinoState } from '../state.js';

export function drawDinoCharacter(ctx, x, y, state) {
  const sprite = dinoState.sprite;
  if (!sprite.loaded || !sprite.image) {
    // Fail-safe while the network sprite is loading.
    ctx.fillStyle = '#1e1e1e';
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

export function drawDinoObstacle(ctx, obs, spriteReady) {
  if (!spriteReady) {
    ctx.fillStyle = '#2d2d2d';
    ctx.fillRect(Math.floor(obs.x), Math.floor(obs.y), obs.w, obs.h);
    return;
  }

  const sprite = dinoState.sprite;
  if (obs.type === 'ptero') {
    const src = sprite.frames.ptero;
    const sx = src.sx + src.sw * (obs.frame || 0);
    ctx.drawImage(sprite.image, sx, src.sy, src.sw, src.sh, Math.floor(obs.x), Math.floor(obs.y), obs.w, obs.h);
    return;
  }

  const src = obs.type === 'cactusLarge' ? sprite.frames.cactusLarge : sprite.frames.cactusSmall;
  const sourceX = src.sx + (src.sw * obs.size) * (0.5 * (obs.size - 1));
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

export function drawDinoCloud(ctx, x, y, spriteReady) {
  if (!spriteReady) {
    ctx.fillStyle = '#d8d8d8';
    ctx.fillRect(Math.floor(x), Math.floor(y + 4), 36, 9);
    ctx.fillRect(Math.floor(x + 12), Math.floor(y), 16, 10);
    return;
  }

  const src = dinoState.sprite.frames.cloud;
  ctx.drawImage(dinoState.sprite.image, src.sx, src.sy, src.sw, src.sh, Math.floor(x), Math.floor(y), src.sw, src.sh);
}

export function drawDinoHorizon(ctx, groundY, width, spriteReady) {
  if (!spriteReady) {
    ctx.fillStyle = '#444';
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
