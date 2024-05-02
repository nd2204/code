_G.love = require 'love'

function love.load()
  love.graphics.setBackgroundColor(0.5,0.5,1)
  _G.number = 0
end

function love.update(dt)
  _G.number = dt
end

function love.draw()
  love.graphics.print(_G.number)
end
