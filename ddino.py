import os
from functools import partial

import keyboard
import serial


directions = {
    "up": "up",
    "left": "left",
    "right": "right",
    "down": "down",
}
key_actions = {
    "start": keyboard.press,
    "end": keyboard.release,
}

actions = {
    f"{direction}-{action}": partial(key_actions[action], hotkey=directions[direction])
    for direction in directions
    for action in key_actions
}


def get_path():
    for index in range(3):
        path = f"/dev/ttyACM{index}"
        if os.path.exists(path):
            return path
    raise Exception("No device found")


def main():
    path = get_path()
    s = serial.Serial(path, 9600, timeout=5)
    while True:
        data = s.readline()

        data = data.decode().strip()
        action = actions.get(data)
        if action:
            action()


if __name__ == "__main__":
    main()
