# nlp-time-parser

nlp-time-parser is a command-line tool that recognizes date and time using regex.

It supports multiple formats, such as "12-07-2023" and "12th of July 2023", passed as command line arguments.


## Motivation

This tool was developed as the final assignment for a Natural Language Processing (NLP) course during the Winter semester of 2024 at my university. The goal was to create a practical application that demonstrates the power of regex in parsing and recognizing patterns in natural language.


## Tested Systems

This project has been tested on the following systems:

- MacOS 14.3 (Sonoma)
- Debian 12 (Bookworm)
- Manjaro 23.1 (Vulcan)


## Requirements

To build and run this project, you'll need:

- C++17 or higher
- CMake


## Build

Follow these steps to build the project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/ryouze/nlp-time-parser.git
   ```

2. **Generate the build system**:
   ```bash
   cd nlp-time-parser
   mkdir build && cd build
   cmake ..
   ```

3. **Compile the project**:
    ```bash
    make -j
    ```

After successful compilation, you can run the program using `./nlp-time-parser`.

The mode is set to `Release` by default. To build in `Debug` mode, use `cmake -DCMAKE_BUILD_TYPE=Debug ..`.


## Usage

To analyze text, pass it as a command line argument. Each argument will be analyzed separately.

```bash
./nlp-time-parser  "mon 15 january 2023" "I will be there on Friday, 24.05.2009 at 8:00 pm (24th of may, 2009)" "It's 15 jan 24 (monday)"
```

Output:

```
[INFO] Input: mon 15 january 2023
[INFO] Output:
        (1) Date = [15 january 2023]
        (2) Time = []
        (3) Day of the week = [mon]
--------------------------------------------------------------------------------
[INFO] Input: I will be there on Friday, 24.05.2009 at 8:00 pm (24th of may, 2009)
[INFO] Output:
        (1) Date = [24.05.2009, 24th of may 2009]
        (2) Time = [8:00 pm]
        (3) Day of the week = [friday]
--------------------------------------------------------------------------------
[INFO] Input: It's 15 jan 24 (monday)
[INFO] Output:
        (1) Date = [15 jan 24]
        (2) Time = []
        (3) Day of the week = [monday]
--------------------------------------------------------------------------------
```

If no arguments are provided, the program will use placeholder text.

```bash
./nlp-time-parser
```

Output:

```
[INFO] Input: The first version was released on 12-07-2008 (12th of july 2008).
[INFO] Output:
        (1) Date = [12-07-2008, 12th of july 2008]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: Next Release will might come on 12 July 2009.
[INFO] Output:
        (1) Date = [12 july 2009]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The due date for payment is 2023-09-1.
[INFO] Output:
        (1) Date = [2023-09-1]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The date on which the Constitution of Poland came into effect on 17 october 1997.
[INFO] Output:
        (1) Date = [17 october 1997]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The meeting is scheduled for 05/12/2022.
[INFO] Output:
        (1) Date = [05/12/2022]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The lunar eclipse will occur on Monday, 16/05/2022.
[INFO] Output:
        (1) Date = [16/05/2022]
        (2) Time = []
        (3) Day of the week = [monday]
--------------------------------------------------------------------------------
[INFO] Input: The solar eclipse will occur on 2022-10-25.
[INFO] Output:
        (1) Date = [2022-10-25]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The event is on 2-Jan-2023.
[INFO] Output:
        (1) Date = [2-jan-2023]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The marathon is on 3rd Jan 2023 (Tue).
[INFO] Output:
        (1) Date = [3rd jan 2023]
        (2) Time = []
        (3) Day of the week = [tue]
--------------------------------------------------------------------------------
[INFO] Input: The festival is on 4th january 23.
[INFO] Output:
        (1) Date = [4th january 23]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The concert is on 5-may-19 (5th may 19).
[INFO] Output:
        (1) Date = [5-may-19, 5th may 19]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The exhibition is on 6 jan-23.
[INFO] Output:
        (1) Date = [6 jan-23]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The fair is on 7 Jan-13.
[INFO] Output:
        (1) Date = [7 jan-13]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The event is on 8 apr 23 (8th of april 2023).
[INFO] Output:
        (1) Date = [8 apr 23, 8th of april 2023]
        (2) Time = []
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: See you on Sunday at 10:30 am.
[INFO] Output:
        (1) Date = []
        (2) Time = [10:30 am]
        (3) Day of the week = [sunday]
--------------------------------------------------------------------------------
[INFO] Input: See you on Tuesday at 18:30.
[INFO] Output:
        (1) Date = []
        (2) Time = [18:30]
        (3) Day of the week = [tuesday]
--------------------------------------------------------------------------------
[INFO] Input: I work from 9am to to 5pm and he works from 8:00 am to 4:30 pm.
[INFO] Output:
        (1) Date = []
        (2) Time = [9am, 5pm, 8:00 am, 4:30 pm]
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The meeting is scheduled for Wednesday, 3rd June 2023 at 3:30 pm.
[INFO] Output:
        (1) Date = [3rd june 2023]
        (2) Time = [3:30 pm]
        (3) Day of the week = [wednesday]
--------------------------------------------------------------------------------
[INFO] Input: The webinar begins at 2:00 pm on 5th August 2023.
[INFO] Output:
        (1) Date = [5th august 2023]
        (2) Time = [2:00 pm]
        (3) Day of the week = []
--------------------------------------------------------------------------------
[INFO] Input: The workshop is on Thursday, 6th September 2023 at 4:00 pm.
[INFO] Output:
        (1) Date = [6th september 2023]
        (2) Time = [4:00 pm]
        (3) Day of the week = [thursday]
--------------------------------------------------------------------------------
```

## Contributing

I doubt anyone will be interested in contributing to this project, but if you are, feel free to open an issue or submit a pull request.


## License

This project is released into the public domain and is licensed under the Unlicense.
