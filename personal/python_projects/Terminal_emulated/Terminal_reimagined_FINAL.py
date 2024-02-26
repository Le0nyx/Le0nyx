# Author: Leon Astner
# Date: 26.02.2024

import tkinter as tk
import customtkinter
import psutil
from datetime import datetime
import subprocess
import os

# Currently no more issues known
# Code is made for windows


class MyApp(customtkinter.CTk):
    def __init__(self):
        super().__init__()
        self.title("Terminal Reimagined")
        self.geometry("1300x700")
        self.resizable(True, True)
        
        self.current_frame = None
        self.switch_frame(StartPage)
        
    def switch_frame(self, frame_class):
        new_frame = frame_class(self)
        if self.current_frame is not None:
            self.current_frame.destroy()
        self.current_frame = new_frame
        self.current_frame.pack()
   

class StartPage(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
          
        leftframe = customtkinter.CTkFrame(master)
        leftframe.pack(side="left", fill="both", expand=True)
        rightframe = customtkinter.CTkFrame(master)
        rightframe.pack(side="left", fill="both", expand=True)

        frame1 = customtkinter.CTkFrame(leftframe)
        frame1.pack(side="top", fill="both", expand=False)
        textview2 = customtkinter.CTkTextbox(frame1, font=("Lucida Sans Unicode", 14), state="disabled", border_width=3)
        textview2.pack(side="left", fill="both", expand=True) 
        output = subprocess.check_output("dir", shell=True)
        textview2.configure(state="normal")
        textview2.delete("1.0", "end")
        textview2.insert("end", output)
        textview2.configure(state="disabled")
            
        frame2 = customtkinter.CTkFrame(leftframe)
        frame2.pack(side="top", fill="both", expand=False)
        label2 = customtkinter.CTkLabel(frame2, font=("Lucida Sans Unicode", 14))
        label2.pack(side="left")

        frame3 = customtkinter.CTkFrame(leftframe)
        label3 = customtkinter.CTkLabel(frame3, text="\nTerminal: ", font=("Lucida Sans Unicode", 14))
        label3.pack(side="top", fill="x", expand=False)
        frame3.pack(side="top", fill="both", expand=True)
        terminal_output = customtkinter.CTkTextbox(frame3, font=("Lucida Sans Unicode", 14), state="disabled", border_width=3)
        terminal_output.pack(side="top", fill="both", expand=True)
        scrollbar = customtkinter.CTkScrollbar(frame3)
        terminal_output.configure(yscrollcommand=scrollbar.set)
        scrollbar.configure(command=terminal_output.yview)

        terminal_input = customtkinter.CTkEntry(frame3, font=("Lucida Sans Unicode", 14))
        terminal_input.pack(side="top", fill="x", padx=5, pady=5)
        
        # function to execute commands in shell and get them into the terminal with working directory update
        def execute_command(event=None): 
            command = terminal_input.get()
            if command.startswith("cd"):
                command_parts = command.split(" ")
                if len(command_parts) < 2:
                    output = "Please specify a directory."
                else:
                    directory = command_parts[1]
                    try:
                        os.chdir(directory)
                        output = f"Changed directory to: {os.getcwd()}"
                    except FileNotFoundError:
                        output = f"Directory not found: {directory}"
            else:
                output = subprocess.check_output(command, shell=True)
            terminal_output.configure(state="normal")
            terminal_output.insert("end", "\n------------------------\n\n\n")
            terminal_output.insert("end", output)
            terminal_output.configure(state="disabled")
            terminal_output.see("end")
            terminal_input.delete(0, "end")
            if "cd" in command:
                update_textview2()
                
        def update_textview2():
            output = subprocess.check_output("dir", shell=True)
            textview2.configure(state="normal")
            textview2.delete("1.0", "end")
            textview2.insert("end", output)
            textview2.configure(state="disabled")
        terminal_input.bind("<Return>", execute_command)

        frame4 = customtkinter.CTkFrame(rightframe)
        frame4.pack(side="top", fill="both", expand=False)

        button2 = customtkinter.CTkButton(frame4, text="Paint", command=buttonPAI_click, width=0, font=("Lucida Sans Unicode", 14))
        button2.pack(side="left", fill="none", pady=5, padx=5, anchor="w")

        button3 = customtkinter.CTkButton(frame4, text="Explorer", command=buttonEXP_click, width=0, font=("Lucida Sans Unicode", 14))
        button3.pack(side="left", fill="none", padx=5, pady=5, anchor="w")

        button4 = customtkinter.CTkButton(frame4, text="Calculator", command=buttonCAL_click, width=0, font=("Lucida Sans Unicode", 14))
        button4.pack(side="left", fill="none", pady=5, padx=5, anchor="w")
        
        button5 = customtkinter.CTkButton(frame4, text="Exit", command=buttonEXI_click, width=0, font=("Lucida Sans Unicode", 14))
        button5.pack(side="left", fill="none", padx=35, pady=5, anchor="w")

        frame5 = customtkinter.CTkFrame(rightframe)
        frame5.pack(side="top", fill="both", expand=True)
        label5 = customtkinter.CTkLabel(frame5, text="\nNotes (doesn't save): ", font=("Lucida Sans Unicode", 14))
        label5.pack(side="top")
        textview1 = customtkinter.CTkTextbox(frame5, font=("Lucida Sans Unicode", 14), border_width=3)
        textview1.pack(side="top", fill="both", expand=True)
        # Update frame1 and frame2 every second
        self.update_frames(frame1, label2)

    def update_frames(self, frame1, label2):
        def update():
            memory = psutil.virtual_memory()
            memory_usage = memory.percent
            disk_usage = psutil.disk_usage('/')
            battery_info = psutil.sensors_battery()
            current_time = datetime.now().strftime("%d-%m-%Y   %H:%M")
            label2.configure(text=f"\n RAM Usage: {memory_usage}%    Disk Usage: {disk_usage.percent}%    Battery: {battery_info.percent}%          {current_time}")
           # Schedule the next update
            frame1.after(1000, update)
        # Start the initial update
        update()            


def buttonPAI_click():
    subprocess.Popen("mspaint.exe")

def buttonEXP_click():
    subprocess.Popen("explorer.exe")

def buttonCAL_click():
    subprocess.Popen("calc.exe")

def buttonEXI_click():
    app.quit()

if __name__ == "__main__":
    app = MyApp()
    app.mainloop()
    
