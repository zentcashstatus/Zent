![Zent Cash](https://github.com/ZentCashFoundation/brand/blob/master/logo/wordmark/zentcash_wordmark_color.png "Zent Cash")
#### Zent Cash is a private, fast, and easy way to send money to friends and businesses.

[![Discord](https://img.shields.io/discord/527428494154792960?label=Discord%20-%20Zent%20Cash%20[ZTC])](https://discord.gg/tfaUE2G) 
[![GitHub issues](https://img.shields.io/github/issues/ZentCashFoundation/Zent?label=Issues)](https://github.com/ZentCashFoundation/Zent/issues)
[![GitHub contributors](https://img.shields.io/github/contributors-anon/ZentCashFoundation/Zent?label=Contributors)](https://github.com/ZentCashFoundation/Zent/graphs/contributors) 
[![GitHub All Releases](https://img.shields.io/github/downloads/ZentCashFoundation/Zent/total?label=Downloads)](http://latest.zent.cash) 
![Version](https://img.shields.io/github/v/release/ZentCashFoundation/Zent)

### Contributing to Zent Cash

We are a community of people across the world giving our time to make this software better. There are many ways you can help or join us:

-   If you'd like to report a bug, [fill out a bug report](https://github.com/ZentCashFoundation/Zent/issues)
-   If you'd like to submit code for a bug you fixed, [submit a pull-request](https://github.com/ZentCashFoundation/Zent/compare)
-   If you're a tester submitting tests you've done on a Release Candidate, [click here](https://github.com/ZentCashFoundation/Zent/issues/new?template=release-candidate.md)
-   If you're a beginner developer, and want a list of easy things you can accomplish to help, [click here for a list of TODOs](https://github.com/ZentCashFoundation/Zent/labels/GOOD%20FIRST%20ISSUE)
-   **Everyone else just click the ★ star at the top of this repository 😊 It really helps us out!**

For anyone else wishing to help the community or who needs answers to questions not covered in this document, join us in our [Discord Chat](http://chat.zent.cash) here.

### Zent Cash Build Branches

#### **Master**

[![Build](https://github.com/ZentCashFoundation/Zent/actions/workflows/matrix.yml/badge.svg?branch=master)](https://github.com/ZentCashFoundation/Zent/actions/workflows/matrix.yml)

### Installing Zent Cash

To use Zent Cash, you will need a way to connect to the network, and a wallet to store your funds. This software includes those things for you, you can compile it yourself, or you can download the ones we have compiled for you.
Here is a script to download and run the Zent Daemon in an automated way.

```bash
#!/bin/bash
set -e

# Variables
ZENT_VERSION="v1.28.4"
ZENT_URL="https://github.com/ZentCashFoundation/Zent/releases/download/${ZENT_VERSION}/ZentCash-${ZENT_VERSION}-linux.tar.gz"
INSTALL_DIR="/usr/local/bin"
DOWNLOAD_DIR="/tmp/zentcash"

# Create a temporary directory for download
mkdir -p ${DOWNLOAD_DIR}
cd ${DOWNLOAD_DIR}

# Download and extract the ZentCash binary
wget ${ZENT_URL}
tar -xvf ZentCash-${ZENT_VERSION}-linux.tar.gz

# Move the necessary binaries to the installation directory
sudo mv ZentCash-${ZENT_VERSION}/Zentd ${INSTALL_DIR}
sudo mv ZentCash-${ZENT_VERSION}/zentwallet ${INSTALL_DIR}
sudo mv ZentCash-${ZENT_VERSION}/wallet-api ${INSTALL_DIR}
sudo mv ZentCash-${ZENT_VERSION}/Zent-service ${INSTALL_DIR}

# Clean up the temporary files
cd /
rm -rf ${DOWNLOAD_DIR}

# Create necessary directories for data and logs
sudo mkdir -p /datadir /app/logs /app/checkpoints

# Change to root directory to avoid getcwd errors
cd /

# Install Node.js and PM2 if not already installed
if ! command -v pm2 &> /dev/null
then
    curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
    sudo apt-get install -y nodejs
    sudo npm install -g pm2
fi

# Command to run Zentd
ZENTD_CMD="${INSTALL_DIR}/Zentd \
    --log-file /app/logs/zentcashd.log \
    --log-level 2 \
    --data-dir /datadir \
    --db-max-open-files 100 \
    --db-read-buffer-size 10 \
    --db-threads 8 \
    --db-write-buffer-size 512 \
    --allow-local-ip false \
    --hide-my-port false \
    --p2p-bind-ip 0.0.0.0 \
    --p2p-bind-port 21688 \
    --rpc-bind-ip 127.0.0.1 \
    --rpc-bind-port 21698 \
    --enable-blockexplorer false \
    --enable-cors '*' \
    --fee-address Ze3eeYHXfJH2SaghicPsKgdP6HC5ehZHe4uRCmi92rpTYRhS6oSeu6E4QKzodiSHTgNf9Yks743cteLQ875Pfnny2GfV2ihDq \
    --fee-amount 0"

# Start Zentd with PM2 without using ecosystem file
pm2 start bash --name zentd -- -c "${ZENTD_CMD}"

# Configure PM2 to start on boot and save the current configuration
pm2 startup
pm2 save

echo "Zentd is running under PM2 with the configured parameters."
```

To compile from sourcecode yourself, [click here for build instructions](https://github.com/ZentCashFoundation/Zent/blob/dev/COMPILE.md).


### A note for contributing developers

Hello, and thank you for helping us! Our work makes use of many brilliant projects from other communities who contributed their code which helped us get to where we are now. To make sure we're always doing things the right way, we try to make sure we get the proper license header in every file we modify. By the terms of this project's license, any open source project may use our software, but the licenses may only be appended to, not altered. 

See [src/config/CryptoNoteConfig.h](https://github.com/ZentCashFoundation/Zent/blob/9a8ca3b76d55d73bc0797ecfd5b6aa8bff18edf8/src/config/CryptoNoteConfig.h#L4) for an example.

```
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2019-2023, The Zent Cash Developers
//
// Please see the included LICENSE file for more information.
```
