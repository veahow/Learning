#!/usr/bin/python
# Filename : Backup_Windows_Ver1.py

import os
import time

# 1. The files and directories to be backed up are specified in a list.
source = [r'C:\Users\veahow\Pictures']
# Windows : use this source

# 2. The backup must be stored in a main backup directory
target_dir = r'C:\Users\veahow\Backup\\'
# Remember to change this to what you will be using

# 3. The files are backed up into a zip file
# 4. The name of the zip archive is the current date and time
target = target_dir + time.strftime('%Y%m%d%H%M%S') + '.zip'

# 5. We use the zip command in Windows to put the files in a zip archive
zip_command = "7z a %s %s" % (target, ' '.join(source))

# Run the backup
if os.system(zip_command) == 0:
    print('Successful backup to', target)
else:
    print('Backup failed')

