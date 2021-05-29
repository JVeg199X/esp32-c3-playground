# Welcome

Intro text to come later

## Configuring Your Environment

I recommend following [the official ESP32-C3 Get Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html).
I recommend using Linux. I tried Windows and could not get it working properly. Use Windows or OSX at your own risk!

1. For "**Step 1. Install prerequisites**" do it. Copied below
    ```bash
    sudo apt install git wget flex bison gperf python3 python3-pip python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
    ```
1. For "**Step 2. Get ESP-IDF**" and "Step 3. Set up the tools" don't do the manual setup, instead install the vscode extension and do the guided setup.
use all the default paths.
install the master repo
https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md
1. For "**Step 3. Set up the tools**" the vscode extension should also automatically install the tools
The "Download Tools" button acted strangely for me. I had to click it repeatedly until the download started. Manually creating the tools dir first may help.
1. For "**Step 4. Set up the environment variables**" I recommend adding this to the end of your `~/.profile` file so that the IDF environment variables get set each time you log in and/or start WSL. You can run the command right now for it to take effect, or restart your shell.
    ```bash
    # Set up IDF
    . $HOME/esp/esp-idf/export.sh
    ```
1. For "**Step 5. Start a Project**" you can clone this repo and open it in vscode.
    ```
    cd ~/
    git clone https://github.com/AEFeinstein/esp32-c3-playground.git
    code esp32-c3-playground
    ```
1. For "**Step 6. Connect Your Device**" set the following environment variables in `~/.bashrc`. Note this is for WSL, and the port number should be replaced with the port on your machine. Restart your shell afterwards for these to take effect.
    ```bash
    export ESP32_C3_PORT=/dev/ttyS3
    export ESP32_C3_PORT_WIN=COM3
    ```
1. For "**Step 7. Configure**" this should already be done. You can do it again if you want to.
1. For "**Step 8. Build the Project**" just click "ctrl+b" in vscode. The default build task should do its thing.
1. For "**Step 9. Flash onto the Device**" the default build task should have already done this for you! The build task also runs `putty.exe` to open up a serial monitor, so I recommend installing putty on Windows. I've found the baud 2000000 is the fastest it will program at, but you may need to slow it down in `burn-dbg.sh`

## Troubleshooting

Reread the [Get Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html), then google your issue, then ask me about it. All troubleshooting issues should be written down here for posterity.

## Tips

To add more source files, they either need to be in the `main` folder, and added to the `CMakeLists.txt` file there, or in a subdirectory of the `components` folder with it's own `CMakeLists.txt`. The folder names are specific. You can read up on the [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) if you're curious.

There are a lot of example projects in the IDF that are worth looking at.
