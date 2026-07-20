<div align="center">

# 🏓 Pong Game

A classic Pong game built with **C++** and **raylib** — featuring smooth paddle physics, CPU AI, score tracking, and a clean retro aesthetic.

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![raylib](https://img.shields.io/badge/raylib-white?style=for-the-badge&logo=raylib&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

</div>

---

## 📸 Preview

> Two-player style Pong with CPU opponent, score tracking, and serve mechanic.

---

## 🎮 Gameplay

| Action | Key |
|--------|-----|
| Move Paddle Up | `↑` Arrow Key |
| Move Paddle Down | `↓` Arrow Key |
| Serve Ball | `Space` |
| Restart (after game over) | `Space` |

- First to **5 points** wins
- Ball resets to center after each point — press `Space` to serve
- CPU paddle tracks the ball automatically

---

## 🚀 Getting Started

### Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/) (with C++ build tools)
- [Git](https://git-scm.com/)
- Windows x64

> ⚠️ **raylib must be installed via vcpkg before running the project**, regardless of which option you choose below.

---

### 📦 Step 1 — Install raylib (Required for Both Options)

#### Set up vcpkg
Open **PowerShell** and run the following commands:
```powershell
1. git clone https://github.com/microsoft/vcpkg.git
2. cd vcpkg
3. ./bootstrap-vcpkg.bat
4. ./vcpkg integrate install
```

#### Install raylib via vcpkg
```powershell
./vcpkg install raylib:x64-windows
```

> ⏳ This may take a few minutes on first install. Once done, vcpkg will automatically link raylib to all Visual Studio projects on your machine.

---

### ▶️ Step 2 — Run the Project

Once raylib is installed, choose either option below:

---

#### Option A — Quick Start with the `.zip` (Recommended)

A complete, ready-to-open Visual Studio project is included in the `pong-game` folder as a `.zip` file.

1. **Extract** the `.zip` file
2. Open the extracted folder and double-click the **`.sln`** file
3. Set the build target to **x64 Release** (or Debug)
4. Press **`Ctrl+F5`** to build and run

---

#### Option B — Build from Source (`pong-game.cpp`)

If you'd prefer to set up the project yourself using just the `.cpp` file:

1. Open **Visual Studio** → Create a new **Empty C++ Project**
2. Add `pong-game.cpp` to the project source files
3. Set the platform to **x64**
4. Press **`Ctrl+F5`** to build and run

> vcpkg's `integrate install` from Step 1 will automatically link raylib — no manual configuration needed.

---

## ⚙️ How It Works

The project uses three core classes:

- **`Ball`** — handles movement, wall bouncing, scoring, and reset logic
- **`Paddle`** — player-controlled paddle with boundary clamping
- **`CpuPaddle`** — inherits `Paddle`, tracks ball Y position automatically

Collision detection uses raylib's `CheckCollisionCircleRec`, with directional correction to prevent the ball from clipping through paddles.

---

## 🛠️ Built With

- [C++17](https://en.cppreference.com/w/cpp/17)
- [raylib](https://www.raylib.com/) — simple and easy-to-use game library
- [vcpkg](https://vcpkg.io/) — C/C++ dependency manager by Microsoft

---

## 📄 License

This project is open source and available under the [MIT License](https://github.com/Sharjeel7911/pong-game/blob/main/LICENSE).

---

<div align="center">
Made with ❤️ and C++ <br>
Special thanks to <a href="https://www.youtube.com/watch?v=VLJlTaFvHo4">Programming With Nick</a> for guidance
</div>
