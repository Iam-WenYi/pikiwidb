/*
 * pikiwidb_logo.h
 *     Responsible for defining the text form of the PikiwiDB logo, 
 * the output of this LOGO must be combined with the definition 
 * in practice.
 * 
 * Copyright (c) 2023-present, Qihoo, Inc.  All rights reserved.
 * 
 * src/pikiwidb_logo.h
 * 
 */

#pragma once

const char* pikiwidbLogo =
    "\n______   _  _     _            _ ______ ______  \n"
    "| ___ \\ (_)| |   (_)          (_)|  _  \\| ___ \\ \n"
    "| |_/ /  _ | | __ _ __      __ _ | | | || |_/ /  PikiwiDB(%s) %d bits \n"  // version and
    "|  __/  | || |/ /| |\\ \\ /\\ / /| || | | || ___ \\ \n"
    "| |     | ||   < | | \\ V  V / | || |/ / | |_/ /  Port: %d\n"
    "\\_|     |_||_|\\_\\|_|  \\_/\\_/  |_||___/  \\____/   https://github.com/OpenAtomFoundation/pikiwidb \n\n\n";
