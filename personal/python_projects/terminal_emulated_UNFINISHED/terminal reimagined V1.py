import customtkinter
import tkinter as tk
import psutil
import time
from datetime import datetime



def button1_click():
    print("hello")




def create_widgets():
    #creating 2 main frames  LEFT and RIGHT
    leftframe = customtkinter.CTkFrame(root)
    leftframe.pack(side="left", fill="both", expand=True)  # Pack the frame into the root window
    rightframe = customtkinter.CTkFrame(root)
    rightframe.pack(side="left", fill="both", expand=True)

    # creating 3 frames for 3 parts on the LEFT frame
    frame1 = customtkinter.CTkFrame(leftframe)
    frame1.pack(side="top", fill="both", expand=True)
    label1 = customtkinter.CTkLabel(frame1, text="Directory:", font=("Lucida Sans Unicode", 14))
    label1.pack(side="left")

    frame2 = customtkinter.CTkFrame(leftframe)
    frame2.pack(side="top", fill="both", expand=False)

    #calculations
    memory = psutil.virtual_memory()
    memory_usage = memory.percent
    current_time = datetime.now().strftime("%d-%m-%Y   %H:%M:%S")
    label2 = customtkinter.CTkLabel(frame2, text=f"\n Memory Usage: {memory_usage}%        {current_time}", font=("Lucida Sans Unicode", 14))
    label2.pack(side="left")

    frame3 = customtkinter.CTkFrame(leftframe)
    frame3.pack(side="top", fill="both", expand=True)
    label3 = customtkinter.CTkLabel(frame3, text="Terminal:", font=("Lucida Sans Unicode", 14))
    label3.pack(side="left")


    # creating 2 frames for the 2 parts on the RIGHT frame
    frame4 = customtkinter.CTkFrame(rightframe)
    frame4.pack(side="top", fill="both", expand=False)

    #buttons into the frame
    button1 = customtkinter.CTkButton(frame4, text="#1", command=button1_click, width=0, font=("Lucida Sans Unicode", 14))
    button1.pack(side="left", padx=5, pady=5, anchor="w", fill="none")

    button2 = customtkinter.CTkButton(frame4, text="#2", command=button1_click, width=0, font=("Lucida Sans Unicode", 14))
    button2.pack(side="left", pady=5, padx=5, anchor="w", fill="none")

    button3 = customtkinter.CTkButton(frame4, text="#3", command=button1_click, width=0, font=("Lucida Sans Unicode", 14))
    button3.pack(side="left", padx=5, pady=5, anchor="w", fill="none")

    button4 = customtkinter.CTkButton(frame4, text="#4", command=button1_click, width=0, font=("Lucida Sans Unicode", 14))
    button4.pack(side="left", pady=5, padx=5, anchor="w", fill="none")

    button5 = customtkinter.CTkButton(frame4, text="Calculator", command=button1_click, width=0, font=("Lucida Sans Unicode", 14))
    button5.pack(side="left", padx=35, pady=5, anchor="w",fill="none")


    frame5 = customtkinter.CTkFrame(rightframe)
    frame5.pack(side="top", fill="both", expand=True)
    label5 = customtkinter.CTkLabel(frame5, text="\n1. Txt widget")
    label5.pack(side="top")
    textview1 = customtkinter.CTkTextbox(frame5, font=("Lucida Sans Unicode", 14))
    textview1.pack(side="top", fill="both", expand=True)
    
    




# set appearance and color theme of the window
customtkinter.set_appearance_mode("system")
customtkinter.set_default_color_theme("dark-blue")

# creates the window and size
root = customtkinter.CTk()
root.geometry("1300x700")
# Create the main window
root.title("Terminal Reimagined")

#creates the widgets in the window
create_widgets()


root.mainloop()
