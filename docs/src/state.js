import {
  DINO_SPRITE_URL,
  DINO_INITIAL_SPEED,
  DINO_MIN_SPAWN_GAP,
} from './config.js';

// UI State
export const uiState = {
  zTop: 100,
  taskbarWindows: {},
  windowStates: {}, // 'open' | 'minimized' | 'closed'
};

// Game State
export const dinoState = {
  initialized: false,
  running: false,
  gameOver: false,
  ducking: false,
  score: 0,
  speed: DINO_INITIAL_SPEED,
  lastTime: 0,
  nextSpawn: 0,
  rafId: 0,
  obstacles: [],
  clouds: [],
  groundOffset: 0,
  runFrame: 0,
  runFrameTimer: 0,
  player: {
    x: 80,
    y: 0,
    w: 36,
    h: 56,
    vy: 0,
    onGround: true,
  },
  minSpawnGap: DINO_MIN_SPAWN_GAP,
  sprite: {
    url: DINO_SPRITE_URL,
    image: null,
    loaded: false,
    failed: false,
    frames: {
      idle: { sx: 848, sy: 2, sw: 44, sh: 47 },
      run0: { sx: 936, sy: 2, sw: 44, sh: 47 },
      run1: { sx: 980, sy: 2, sw: 44, sh: 47 },
      crash: { sx: 1068, sy: 2, sw: 44, sh: 47 },
      duck0: { sx: 1111, sy: 19, sw: 59, sh: 30 },
      duck1: { sx: 1170, sy: 19, sw: 59, sh: 30 },
      cloud: { sx: 86, sy: 2, sw: 46, sh: 14 },
      horizon: { sx: 2, sy: 54, sw: 600, sh: 12 },
      cactusSmall: { sx: 228, sy: 2, sw: 17, sh: 35 },
      cactusLarge: { sx: 332, sy: 2, sw: 25, sh: 50 },
      ptero: { sx: 134, sy: 2, sw: 46, sh: 40 },
    },
  },
};

export const minesweeperState = {
  initialized: false,
  bound: false,
  running: false,
  gameOver: false,
  won: false,
  flagMode: false,
  difficulty: 'beginner',
  width: 9,
  height: 9,
  mines: 10,
  timer: 0,
  timerId: 0,
  firstRevealDone: false,
  board: [],
  revealedCount: 0,
  flagsPlaced: 0,
};
