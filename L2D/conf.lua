function love.conf(t)
    t.identity = "data/saves"
    t.version = "11.4"
    t.console = true
    t.externalstorage = true
    t.gammacorrect = true

    t.window.minwidth = 600
    t.window.minheight = 400
    t.window.resizable = true
    t.window.vsync = true -- default true
end
