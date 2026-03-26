import { dinoState } from '../state.js';

export function ensureDinoSpriteLoaded() {
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

export function isSpriteReady() {
  return dinoState.sprite.loaded && !!dinoState.sprite.image;
}
