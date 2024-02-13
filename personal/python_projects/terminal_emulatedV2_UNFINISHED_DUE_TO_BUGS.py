import customtkinter
import psutil
from datetime import datetime
import subprocess

# The Code is more or less finished
# Code sometimes randomly can crash due to terminal input of unknown commands
# The code until now is also only made for windows and not for linux or mac
# 

def buttonPAI_click():
    subprocess.Popen("mspaint.exe")

def buttonEXP_click():
    subprocess.Popen("explorer.exe")

def buttonCAL_click():
    subprocess.Popen("calc.exe")

def buttonEXI_click():
    root.destroy()


def create_widgets():
    #creating 2 main frames  LEFT and RIGHT
    leftframe = customtkinter.CTkFrame(root)
    leftframe.pack(side="left", fill="both", expand=True)  # Pack the frame into the root window
    rightframe = customtkinter.CTkFrame(root)
    rightframe.pack(side="left", fill="both", expand=True)

    # creating 3 frames for 3 parts on the LEFT frame
    frame1 = customtkinter.CTkFrame(leftframe)
    frame1.pack(side="top", fill="both", expand=False)
    output = subprocess.check_output("dir", shell=True)
    textview1 = customtkinter.CTkTextbox(frame1, font=("Lucida Sans Unicode", 14), state="disabled", border_width=3) # Textbox for the output of the command
    textview1.configure(state="normal")
    textview1.insert("end", output) # Insert the output of the command into the textbox "dir" in this case
    textview1.configure(state="disabled")
    textview1.pack(side="left", fill="both", expand=True) 

    frame2 = customtkinter.CTkFrame(leftframe) # Memory usage and time frame
    frame2.pack(side="top", fill="both", expand=False)
    memory = psutil.virtual_memory()#calculations
    memory_usage = memory.percent
    current_time = datetime.now().strftime("%d-%m-%Y   %H:%M")
    label2 = customtkinter.CTkLabel(frame2, text=f"\n Memory Usage: {memory_usage}%        {current_time}", font=("Lucida Sans Unicode", 14))
    label2.pack(side="left")

    frame3 = customtkinter.CTkFrame(leftframe)  # Terminal frame
    label3 = customtkinter.CTkLabel(frame3, text="\nTerminal: ", font=("Lucida Sans Unicode", 14))
    label3.pack(side="top", fill="x", expand=False)
    frame3.pack(side="top", fill="both", expand=True)
    terminal_output = customtkinter.CTkTextbox(frame3, font=("Lucida Sans Unicode", 14), state="disabled", border_width=3)
    terminal_output.pack(side="top", fill="both", expand=True)
    scrollbar = customtkinter.CTkScrollbar(frame3)
    terminal_output.configure(yscrollcommand=scrollbar.set) #this scrollbar is hidden but keeps the textbox always at lowest position when new text is added
    scrollbar.configure(command=terminal_output.yview)

    terminal_input = customtkinter.CTkEntry(frame3, font=("Lucida Sans Unicode", 14)) # Terminal functionality
    terminal_input.pack(side="top", fill="x", padx=5, pady=5)

    def execute_command(event=None): # Function to execute the command
        command = terminal_input.get()
        output = subprocess.check_output(command, shell=True)
        terminal_output.configure(state="normal")
        terminal_output.insert("end", "\n------------------------\n\n\n")  # Add a line of dashes
        terminal_output.insert("end", output)
        terminal_output.configure(state="disabled")
        terminal_output.see("end")  # Scroll to the end of the textbox
        terminal_input.delete(0, "end")  # Clear the input field
    terminal_input.bind("<Return>", execute_command) # Bind the <Return> event to execute_command function

    # creating 2 frames for the 2 parts on the RIGHT frame
    frame4 = customtkinter.CTkFrame(rightframe)
    frame4.pack(side="top", fill="both", expand=False)

    #buttons into the frame
    button2 = customtkinter.CTkButton(frame4, text="Paint", command=buttonPAI_click, width=0, font=("Lucida Sans Unicode", 14))
    button2.pack(side="left", fill="none", pady=5, padx=5, anchor="w")

    button3 = customtkinter.CTkButton(frame4, text="Explorer", command=buttonEXP_click, width=0, font=("Lucida Sans Unicode", 14))
    button3.pack(side="left", fill="none", padx=5, pady=5, anchor="w")

    button4 = customtkinter.CTkButton(frame4, text="Calculator", command=buttonCAL_click, width=0, font=("Lucida Sans Unicode", 14))
    button4.pack(side="left", fill="none", pady=5, padx=5, anchor="w")

    button5 = customtkinter.CTkButton(frame4, text="Exit", command=buttonEXI_click, width=0, font=("Lucida Sans Unicode", 14))
    button5.pack(side="left", fill="none", padx=35, pady=5, anchor="w")

    frame5 = customtkinter.CTkFrame(rightframe) # Notes frame
    frame5.pack(side="top", fill="both", expand=True)
    label5 = customtkinter.CTkLabel(frame5, text="\nTextbox for Notes: ", font=("Lucida Sans Unicode", 14))
    label5.pack(side="top")
    textview1 = customtkinter.CTkTextbox(frame5, font=("Lucida Sans Unicode", 14), border_width=3)
    textview1.pack(side="top", fill="both", expand=True)
    


# create everything
customtkinter.set_appearance_mode("system") # Set the appearance mode of the window
customtkinter.set_default_color_theme("dark-blue") # Set the color theme of the window
root = customtkinter.CTk() # Create the root window
root.geometry("1300x700") # Set the size of the window
root.resizable(True, True)  # Allow the window to be resized
root.title("Terminal Reimagined") # Set the title of the window
create_widgets() # Create the widgets
root.mainloop()  # Start the application