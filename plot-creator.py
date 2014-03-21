#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import matplotlib
import sys
from datetime import datetime
import os
# from matplotlib.backends.backend_pdf import PdfPages


def to_time(string):
    format = "%H:%M:%S.%f"
    return datetime.strptime(string, format)


def plot_command(command, lines):
    x_values = []
    y_values = []
    max_y = 0

    start = 0
    for i, line in enumerate(lines):
        if line.find(command) != -1:
            start = i + 1
            break

    if (start == 0):
        return

    for line in lines[start:]:

        if line.find('|') == -1:
            break

        (x, y) = line.split('|')
        y = int(y.strip())
        x = x.strip()

        if y > max_y:
            max_y = y

        x_values.append(to_time(x))
        y_values.append(y)

    fig = plt.figure()
    dates = matplotlib.dates.date2num(x_values)
    plt.plot_date(dates, y_values)
    plt.ylabel('duration [ms]')
    plt.xlabel('start time [HH:MM:SS]')
    fig.autofmt_xdate()
    fig.suptitle(command, fontsize=20)
    return fig
    # plt.suptitle(name + "-" + command)
    # plt.show()


input_file = open(sys.argv[1], 'r')
lines = input_file.readlines()
day = os.path.basename(sys.argv[1])[16:18]
month = os.path.basename(sys.argv[1])[18:20]
name = day + '.' + month + '.'

commands = [
    'LFC_LS',
    'LCG_CR',
    'LCG_REP',
    'LFC_MKDIR',
    'LCG_CP',
    'LCG_DEL',
    'LCG_NONE',
    'SRV_ERR',
    'LCG_ERR_TIMEOUT',
    'LCG_ERR_PROXY',
    'LCG_UTIME',
    'LCG_PINGDB',
    'LCG_LR',
    'LCG_AA',
    'LCG_RM',
    'LCG_UNKNOWN'
# pridat serv error ?
    ]

for i in range(len(commands)):
    commands.append(commands[i] + '-Failed')
    commands[i] = commands[i] + '-Good'


# pp = PdfPages(name + 'pdf')
#if not os.path.exists(name):
#    os.mkdir(name)
#
#os.chdir(name)

for command in commands:
    figure = plot_command(command, lines)
    if figure:
        figure.savefig(command)
        print os.path.abspath(command)
    #pp.savefig(figure)
os.chdir('..')

# pp.close()
