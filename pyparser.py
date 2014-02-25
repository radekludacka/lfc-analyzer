#!/usr/bin/python

import sys
import os

def get_list_of_users(result_file):
    lines = open(result_file).readlines()
    users = []
    for line in lines:
        slide = line.find('|')
        colon = line.find(':')
        if colon < slide and colon > 1:
            user = line[0:colon].strip()
            #if not user.find('=') == -1:
            users.append(user)

    return users

def get_command_for_user(user, ifile):
    commands = {} 
    lines = [line.strip() for line in open(ifile)]
    for i, line in enumerate(lines):
        if 0 == line.find(user):
            for j in range(i, len(lines)):
                if i != j and not lines[j].startswith('|'):
                    return commands
                startCommand = lines[j].find('|')
                endCommand = lines[j].rfind(':')
                endValue = lines[j].rfind('|')
                command = lines[j][startCommand + 1: endCommand].strip()
                value = int(lines[j][endCommand + 1: endValue].strip())
                commands[command] = value
            else:
                return commands

    return commands

def get_users_and_their_commands(users, ifile):
    
    users_and_commands = {}
    for user in users:
        commands = get_command_for_user(user, ifile)
        users_and_commands[user] = commands

    return users_and_commands

def get_files_and_their_users_their_commnads(files):

   files_users_commands = {}

   for ifile in files:
       users_in_file = get_list_of_users(ifile)
       files_users_commands[ifile] = get_users_and_their_commands(users_in_file, ifile)

   return files_users_commands

def print_values(result, users, commands):

    users_list = '' 
    for user in users:
        eq_index = user.rfind('=')
        user = user[eq_index + 1:]
        users_list = users_list + ' ' + str(user) + '|||||'
    head_line_one = 'day  \t|' + users_list
    print head_line_one

    command_item = ''
    for command in commands:
        command_item = command_item + str(command) + '|' 
        
    head_line_two = '|' + command_item * len(users)

    print head_line_two

    for key, ifile in sorted(result.items()):
        commands_line = ''
        for user in users:
            if user in ifile:
                users_commands = ifile[user]
                commands_item = ''
                for command in commands:
                    if command in users_commands:
                        number_of_commands = users_commands[command]
                        commands_item = commands_item + str(number_of_commands) + '|'
                    else:
                        commands_item = commands_item + '0|'
                commands_line = commands_line + commands_item
            else:
                commands_line = commands_line + '0|0|0|0|0|'

        print str(key) + '|' + commands_line 

def main(argv):
    commands = ['LFC_LS', 'LCG_CR', 'LCG_REP', 'LCG_LR', 'SRV_ERR'] 
    all_users = set()
    input_files = []
    file_names = []

    for ifile in os.listdir("."):
        if ifile.startswith("result-201"):
            file_names.append(ifile[7:-4])
            input_files.append(ifile)

    #for ifile in sorted(file_names):
    #    print ifile

    for ifile in input_files:
        users = get_list_of_users(ifile)
        for user in users:
            all_users.add(user)     

    result = get_files_and_their_users_their_commnads(input_files)

    all_users = list(all_users)
    print_values(result, all_users, commands)

if __name__ == "__main__":
   main(sys.argv) 
