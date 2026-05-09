#!/usr/bin/env bash
# Exit on any command failure
set -e

# Executes a command with a banner
execute_cmd() {
    local cmd="$@"
    local middle_line="Command: $cmd"
    local middle_line_len=$(echo -n "$middle_line" | wc -m)
    local extra_chars=20
    local total_length=$((middle_line_len + extra_chars))
    local hash_line=$(printf '%*s' "$total_length" | tr ' ' '=')

    printf "\n"
    printf "%s\n" "$hash_line"
    printf "          %s\n" "$middle_line"
    printf "%s\n" "$hash_line"
    printf "\n"

    # Execute the command and check for errors
    if ! eval "$cmd"; then
        echo "Command failed: $cmd"
        exit 1
    fi
}

# Detect if running as root (UID 0)
if [ "$(id -u)" -eq 0 ]; then
    SUDO=""
else
    SUDO="sudo"
fi

# Detect the operating system using uname
OS="$(uname -s)"
INSTALL=""

# Perform necessary setup and get the
# installation command depending on
# the OS
case "$OS" in
    Linux*)
        # Detect the package manager
        PM=""
        if command -v apt-get &> /dev/null; then
            PM="$SUDO apt-get"
            execute_cmd $SUDO apt-get -y update
            execute_cmd $SUDO apt-get -y dist-upgrade
        elif command -v yum &> /dev/null; then
            PM="$SUDO yum"
            execute_cmd $SUDO yum -y update
        # I have no idea why this is here but i'll leave it in case we need later
        # elif command -v dnf &> /dev/null; then
        #     PM="$SUDO dnf"
        #     execute_cmd $SUDO dnf -y upgrade
        else
            echo "No known package manager found"
            exit 1
        fi
        INSTALL="$PM install -y"
        # List of packages to install
        PACKAGES="git g++ make cmake libopencv-dev libeigen3-dev nvidia-cuda-toolkit"
        ;;
    *)
        echo "Unknown Operating System $OS"
        exit 1
        ;;
esac

# Install each package and echo the command
for PACKAGE in $PACKAGES; do
    CMD="$INSTALL $PACKAGE"
    execute_cmd $CMD
done


if command -v nvcc &> /dev/null; then
    printf "\nSUCCESS: nvcc found at $(which nvcc)\n"
else
    printf "\nWARNING: nvcc not found in PATH.\n"
    printf "You may need to add this to your .bashrc or .zshrc:\n"
    printf "export PATH=/usr/local/cuda/bin:\$PATH\n"
    printf "export LD_LIBRARY_PATH=/usr/local/cuda/lib64:\$LD_LIBRARY_PATH\n"
fi
