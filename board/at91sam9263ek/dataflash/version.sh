#!/bin/bash
git log -1 --format='const char boot_hash[] = "%H";' > version.c