import webbrowser
import tkinter as tk
from tkinter import Menu, scrolledtext, filedialog, messagebox, simpledialog

ventana = tk.Tk()
ventana.title("Lector y Editor de Archivos")
ventana.geometry("900x600")
ventana.config(bg="#eaf0f7")

# --- Área de texto ---
texto = scrolledtext.ScrolledText(
    ventana,
    wrap=tk.WORD,
    font=("Consolas", 12),
    bg="#ffffff",
    fg="#000000",
    undo=True,
    autoseparators=True
)
texto.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

# --- Variable global para almacenar la ruta del archivo actual ---
ruta_archivo = None

# --- Funciones del menú Archivo ---
def abrir_archivo():
    global ruta_archivo
    ruta = filedialog.askopenfilename(
        title="Abrir archivo",
        filetypes=[("Archivos de texto", "*.txt"), ("Todos los archivos", "*.*")]
    )
    if ruta:
        with open(ruta, "r", encoding="utf-8") as archivo:
            contenido = archivo.read()
            texto.delete(1.0, tk.END)
            texto.insert(tk.END, contenido)
        ruta_archivo = ruta
        ventana.title(f"Lector y Editor de Archivos - {ruta.split('/')[-1]}")

def guardar():
    global ruta_archivo
    if ruta_archivo:
        with open(ruta_archivo, "w", encoding="utf-8") as archivo:
            archivo.write(texto.get(1.0, tk.END))
        messagebox.showinfo("Guardar", "Archivo guardado correctamente.")
    else:
        guardar_como()

def guardar_como():
    global ruta_archivo
    ruta = filedialog.asksaveasfilename(
        defaultextension=".txt",
        filetypes=[("Archivos de texto", "*.txt"), ("Todos los archivos", "*.*")],
        title="Guardar como"
    )
    if ruta:
        with open(ruta, "w", encoding="utf-8") as archivo:
            archivo.write(texto.get(1.0, tk.END))
        ruta_archivo = ruta
        ventana.title(f"Lector y Editor de Archivos - {ruta.split('/')[-1]}")
        messagebox.showinfo("Guardar como", "Archivo guardado correctamente.")

def buscar_palabra():
    palabra = simpledialog.askstring("Buscar", "Ingrese la palabra a buscar:")
    if palabra:
        contenido = texto.get(1.0, tk.END)
        contador = contenido.lower().count(palabra.lower())

        texto.tag_remove("resaltado", "1.0", tk.END)
        if contador > 0:
            inicio = "1.0"
            while True:
                inicio = texto.search(palabra, inicio, stopindex=tk.END, nocase=True)
                if not inicio:
                    break
                fin = f"{inicio}+{len(palabra)}c"
                texto.tag_add("resaltado", inicio, fin)
                inicio = fin
            texto.tag_config("resaltado", background="yellow", foreground="black")
            messagebox.showinfo("Buscar", f"La palabra '{palabra}' aparece {contador} veces.")
        else:
            messagebox.showinfo("Buscar", f"No se encontró la palabra '{palabra}'.")

# --- Funciones del menú Editar ---
def copiar_texto():
    try:
        seleccion = texto.selection_get()
        ventana.clipboard_clear()
        ventana.clipboard_append(seleccion)
    except tk.TclError:
        pass

def pegar_texto():
    try:
        contenido = ventana.clipboard_get()
        texto.insert(tk.INSERT, contenido)
    except tk.TclError:
        messagebox.showwarning("Pegar", "No hay texto en el portapapeles.")

def cortar_texto():
    try:
        texto.clipboard_clear()
        texto.clipboard_append(texto.selection_get())
        texto.delete(tk.SEL_FIRST, tk.SEL_LAST)
    except tk.TclError:
        messagebox.showwarning("Cortar", "No hay texto seleccionado.")

def seleccionar_todo():
    texto.tag_add("sel", "1.0", tk.END)
    return "break"

def eliminar_texto():
    texto.delete("sel.first", "sel.last")

# --- Crear menú principal ---
barra_menu = Menu(ventana)
ventana.config(menu=barra_menu)

# --- Menú Archivo ---
menu_archivo = Menu(barra_menu, tearoff=0)
menu_archivo.add_command(label="Abrir", command=abrir_archivo)
menu_archivo.add_command(label="Guardar", command=guardar)
menu_archivo.add_command(label="Guardar como", command=guardar_como)
menu_archivo.add_command(label="Buscar", command=buscar_palabra)
menu_archivo.add_separator()
menu_archivo.add_command(label="Salir", command=ventana.quit)
barra_menu.add_cascade(label="Archivo", menu=menu_archivo)

# --- Menú Editar ---
menu_editar = Menu(barra_menu, tearoff=0)
menu_editar.add_command(label="Deshacer", command=lambda: texto.edit_undo())
menu_editar.add_command(label="Rehacer", command=lambda: texto.edit_redo())
menu_editar.add_command(label="Copiar        Ctrl+C", command=copiar_texto, state="disabled")
menu_editar.add_command(label="Pegar          Ctrl+V", command=pegar_texto)
menu_editar.add_command(label="Cortar         Ctrl+X", command=cortar_texto, state="disabled")
menu_editar.add_separator()
menu_editar.add_command(label="Seleccionar todo     Ctrl+E", command=seleccionar_todo)
menu_editar.add_command(label="Eliminar", command=eliminar_texto, state="disabled")
barra_menu.add_cascade(label="Editar", menu=menu_editar)

def actualizar_menu_editar(event=None):
    try:
        texto.selection_get()
        menu_editar.entryconfig("Copiar        Ctrl+C", state="normal")
        menu_editar.entryconfig("Cortar         Ctrl+X", state="normal")
        menu_editar.entryconfig("Eliminar", state="normal")
    except tk.TclError:
        menu_editar.entryconfig("Copiar        Ctrl+C", state="disabled")
        menu_editar.entryconfig("Cortar         Ctrl+X", state="disabled")
        menu_editar.entryconfig("Eliminar", state="disabled")

texto.bind("<<Selection>>", actualizar_menu_editar)

# --- Menú Ayuda ---
menu_ayuda = Menu(barra_menu, tearoff=0)
menu_ayuda.add_command(
    label="Información",
    command=lambda: messagebox.showinfo(
        "Información",
        "Editor de Texto en Python\n\n"
        "Este programa fue desarrollado aplicando los principios de la Programación Orientada a Objetos (POO).\n"
        "Implementa conceptos como clases, métodos, funciones y encapsulamiento, junto con el manejo de archivos\n"
        "para abrir, editar y guardar información. Además, utiliza la biblioteca Tkinter para la creación de una\n"
        "interfaz gráfica funcional e intuitiva."
    )
)
menu_ayuda.add_command(
    label="Manual de Usuario",
    command=lambda: webbrowser.open("https://github.com/ProyectoFinalAlgoritmos/DOCUMENTACION-PROYECTO-FINAL-")
)

menu_ayuda.add_command(
    label="Integrantes",
    command=lambda: messagebox.showinfo(
        "Integrantes",
        "Integrante 1: Caleb Seth Elizar Bobadilla\nNo.Carné: 7690-25-25765\n\n"
        "Integrante 2: Fabio Alexander Gutierrez Castillo\nNo.Carné: 7690-25-14559\n\n"
        "Integrante 3: Hemerson René López Hernández\nNo.Carné: 7690-25-4844"
    )
)
menu_ayuda.add_command(
    label="Acerca de",
    command=lambda: messagebox.showinfo(
        "Acerca de",
        "Lector y editor de archivos.\n"
        "Versión: 1.0\n"
        "Desarrollado en Python.\n"
        "Autores: Caleb, Fabio y Hemerson\n"
        "Proyecto Final de Algoritmos, todos los derechos reservados."
    )
)
barra_menu.add_cascade(label="Ayuda", menu=menu_ayuda)

ventana.bind("<Control-c>", lambda event: copiar_texto())
ventana.bind("<Control-v>", lambda event: pegar_texto())
ventana.bind("<Control-x>", lambda event: cortar_texto())
ventana.bind("<Control-e>", lambda event: seleccionar_todo())

ventana.mainloop()

