open System.Windows.Forms
open System.Runtime.InteropServices
open AIMLbot

[<DllImport("kernel32.dll")>] extern bool FreeConsole()
FreeConsole() |> ignore

let bot = new Bot()
bot.loadSettings()
bot.loadAIMLFromFiles()
let user = new User("User", bot)

let form = new Form(Width = 400, Height = 400, Text = "ChatWithUnknown@localhost", MaximizeBox = false)
let log = new RichTextBox(Dock = DockStyle.Fill, ReadOnly = true)
let input = new TextBox(Dock = DockStyle.Bottom)
let sendButton = new Button(Text = "Send", Dock = DockStyle.Bottom)

let send message = 
    log.Text <- "Bot: " + (bot.Chat(new Request(input.Text, user, bot))).ToString() + 
                "\nYou: " + message + "\n" + log.Text
    input.Text <- ""
    input.Focus() |> ignore

input.KeyDown.Add (fun e -> if e.KeyCode = Keys.Enter
                                then send input.Text
                            else () )

sendButton.Click.Add (fun _ -> send input.Text)

form.Closed.Add (fun _ -> Application.Exit())
    
form.Controls.AddRange([|log; input; sendButton|])
form.Show()

input.Focus() |> ignore

Application.Run()