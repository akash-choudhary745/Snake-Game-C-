# 🐍 Snake Game in C++ (BGI Graphics)

A classic **Snake Game** developed in **C++** using **Windows BGI (graphics.h)**.  
The game features real-time movement, food consumption, collision detection, and restart/exit options via keyboard controls.

---

## 📌 Features

- 🎮 Classic Snake gameplay
- 🧱 Boundary collision detection
- 🔁 Self-collision detection
- 🍎 Random food generation
- 📈 Snake growth on eating food
- 🔄 Restart game option
- ❌ Exit game option
- 🖥️ Graphical interface using **BGI**

---

## 🛠️ Technologies Used

- **Language:** C++
- **Graphics Library:** BGI (`graphics.h`)
- **Compiler:** Turbo C++ / MinGW (with WinBGIm)
- **Platform:** Windows

---

## 🎮 Controls

| Key | Action |
|----|-------|
| ⬆ Arrow | Move Up |
| ⬇ Arrow | Move Down |
| ⬅ Arrow | Move Left |
| ➡ Arrow | Move Right |
| `r` | Restart Game (after Game Over) |
| `a` | Exit Game |

---

## 📷 Screenshot

![Snake Game Screenshot](snake-game.png)

*(Shows Game Over screen with restart and exit options)*

---

## ⚙️ How to Run the Game

### Option 1: Turbo C++
1. Open **Turbo C++**
2. Create a new `.cpp` file
3. Paste the source code
4. Make sure `graphics.h` is properly configured
5. Compile and run

### Option 2: MinGW + WinBGIm
1. Install **MinGW**
2. Setup **WinBGIm graphics library**
3. Compile using:
   ```bash
   g++ snake.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
