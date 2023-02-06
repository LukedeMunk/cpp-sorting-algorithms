# C++ sorting algorithms

Sorting algorithms suitable for Arduino or ESP based microcontrollers. Can be used as library and to visualise sorting algorithms (see `Visualise with SSD1306 display`). The software is tested on the following boards:

* ESP32 DEVKIT V1

## Available sorting algorithms:

Below, there is a list of available algorithms. If you have any requests, please contact me.

* Bubble Sort
* Insertion Sort
* Merge Sort
* Quick Sort
* Selection Sort

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

The software is written, compiled and uploaded using the Arduino IDE (v1.8.13). You could use the online Arduino IDE or other software, but I recommend using the version you can download on [this page](https://www.arduino.cc/en/software). In order to use the Arduino IDE as tool for uploading to the ESP, there are several steps to follow. Please visit the following tutorials:

* https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

### Installing

Clone the repository, copy the `SortingAlgorithms` map in the Arduino libraries map (default path: `C:\Users\\[name]\Documents\Arduino\libraries`). For testing, you can navigate to the `examples` map and try some examples. You can also use the `TestUtility.h` functions to print lists with a single line.

## Visualise with SSD1306 display

If you are looking to a way to visualise different sorting algorithms, then you can use a SSD1306 display. Navigate to the `examples\visualise-sorting-algorithms` map and upload the `visualise-sorting-algorithms.ino` program. Connect the hardware and look at the visualisations. In the map `documentation` you can find a wiring diagram.

## Questions or feedback?

You can submit an issue if you have questions or feedback for this repository. If you are interested in more of my projects, checkout my GitHub [profile](https://github.com/LukedeMunk). If you are interested in hiring me, checkout my [LinkedIn](https://www.linkedin.com/in/luke-de-munk/).

## Authors

* **Luke de Munk** - *Head author* - [LinkedIn](https://www.linkedin.com/in/luke-de-munk/)