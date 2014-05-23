// Eugene Auduchinok, 2014

namespace ChatBot

open System.Windows.Forms
open System.Drawing
open AIMLbot

module Bot =
    let bot = new Bot()
    bot.loadSettings()
    bot.loadAIMLFromFiles()
    let user = new User("User", bot)

    let askBot message = 
        bot.Chat(new Request(message, user, bot)).ToString()

    let createForm () = 
        let form = new Form(Width = 400, Height = 400, Text = "Chat@localhost", MaximizeBox = false, Icon = new Icon("icon.ico"))
        let log = new RichTextBox(Dock = DockStyle.Fill, ReadOnly = true, TabIndex = 2)
        let input = new TextBox(Dock = DockStyle.Bottom, TabIndex = 0)
        let sendButton = new Button(Text = "Send", Dock = DockStyle.Bottom, TabIndex = 1)

        let send message = 
            if not (message.Equals("")) then
                log.Text <- "Bot: " + askBot message + "\nYou: " + message + "\n" + log.Text
                input.Text <- ""
                input.Focus() |> ignore

        input.KeyDown.Add (fun e ->
            if e.KeyCode = Keys.Enter
            then send input.Text
            else () )

        sendButton.Click.Add (fun _ -> send input.Text)
        form.Closed.Add (fun _ -> Application.Exit())

        form.Controls.AddRange([|log; input; sendButton|])
        form.Show()

    createForm ()
    Application.Run()