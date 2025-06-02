# FLAM Assignments - iOS and Android-Set-1
This repository contains solutions to the **Android Assignment Set 1** and **iOS Assignment** provided by FLAM. The Android assignment consists of multiple problems, out of which **Q1, Q2, and Q4** are completed and iOS assignment consists of Challenge 1 : Design Patterns - Music Player Service‬ and Challenge 2 : Metal Shader Programming.

---

## ✅ Completed Questions

| Question | Title                    | Language(s) Used |
|----------|--------------------------|------------------|
| Q1       | LRU Cache Implementation | C++, Java        |
| Q2       | Custom HashMap           | C++, Java        |
| Q4       | Mini Solar System (OpenGL) | C++ (GLFW, GLAD, GLSL) |
| iOS      | Real-Time Filter App       | Swift (Xcode Project)  |


---

## 📁 Folder Structure

```

Android_Set_1
├── Q1
│   ├── cpp
│   │   └── Q1_LRU_Cache.cpp
│   └── java
│       └── LRUCacheApp.java
├── Q2
│   ├── cpp
│   │   └── HashMap.cpp
│   └── java
│       └── MyHashMap.java
├── Q4
│   └── Mini-Solar-System-Visualization/
│       ├── CMakeLists.txt
│       ├── src/
│       ├── shaders/
│       ├── resources/
│       └── build/ (build output)
iOS_Assg
└── RealTimeFilterApp/
    ├── RealTimeFilterApp.xcodeproj
    └── RealTimeFilterApp/
        ├── Info.plist
        ├── RealTimeFilterApp.entitlements
        ├── Renderer/
        │   ├── CameraManager.swift
        │   ├── FilterRenderer.swift
        │   └── MetalRenderer.swift
        ├── Shaders/
        │   └── Shaders.metal
        └── UI/
            ├── AppDelegate.swift
            └── ViewController.swift


````

---

## 🔧 Build & Run Instructions

### Q1 and Q2 (C++)

```bash
cd Q1/cpp
g++ Q1_LRU_Cache.cpp -o lru
./lru

cd ../../Q2/cpp
g++ HashMap.cpp -o hashmap
./hashmap
````

### Q1 and Q2 (Java)

```bash
cd Q1/java
javac LRUCacheApp.java
java LRUCacheApp < input.txt

cd ../../Q2/java
javac MyHashMap.java
java MyHashMap < input.txt
```

### Q4 – OpenGL Solar System (C++)

```bash
cd Q4/Mini-Solar-System-Visualization/build
cmake ..
make
./solar_system
```

> **Note:** Ensure you have OpenGL 3.3+, GLFW, and GLAD dependencies installed.

### iOS – Real-Time Filter App

1. Open the project in Xcode:
   ```bash
   cd iOS_Assg/RealTimeFilterApp/
   open RealTimeFilterApp.xcodeproj
    ````

2. Connect an iOS device (iPhone/iPad)

3. In Xcode:

   * Select your connected device as the target
   * Trust the developer certificate on your iPhone if prompted

4. Press **Run** (▶️) or use `Cmd + R` to build and deploy the app to your device

> **Note:** This app uses **Metal shaders** for real-time filtering. Ensure your device supports Metal and camera access is granted.


---

### 🎮 Controls for Q4 – Mini Solar System

| Control                 | Description                                   |
| ----------------------- | --------------------------------------------- |
| `W` / `S`               | Move forward / backward                       |
| `A` / `D`               | Move left / right                             |
| `Mouse Movement`        | Rotate camera (yaw and pitch – FreeCam)       |
| `Scroll Wheel`          | Zoom in/out (FOV change)                      |
| `Up Arrow / Down Arrow` | Zoom in/out (for static top-down view)        |
| `F`                     | Toggle FreeCam mode (optional if implemented) |
| `ESC`                   | Exit the application                          |

> The camera supports both **FreeCam (FPS-style)** and **Static top-down** modes, configurable in code.

---


## 📸 Screenshots / Demo

*You may include GIFs or images from Q4 here*

---

## 📝 Author

**Gedela Uday Kiran** 

Email: *\[[udaykiranuk1126@gmail.com](mailto:udaykiranuk1126@gmail.com)]*

GitHub: [github.com/UdayKiran112](https://github.com/UdayKiran112)

---

