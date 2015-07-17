import wx
import sys
import wave
import math
import struct
import random
import argparse
#from itertools import *
from Interpreter import Interpreter

class WindowFrame(wx.Frame):
	def __init__(self, parent):
		wx.Frame.__init__(self, parent)
		self.SetTitle('Message box')
		self.panel = wx.Panel(self)
		self.SetSize((3000, 200))
		self.quote = wx.StaticText(self.panel, label="Your quote:")
		self.result = wx.StaticText(self.panel, label="")
		self.result.SetForegroundColour(wx.RED)
		self.button = wx.Button(self.panel, label="Save")
		self.lblname = wx.StaticText(self.panel, label="Your name:")
		self.editname = wx.TextCtrl(self.panel, size=(140, -1), style=wx.TE_PROCESS_ENTER)
		#self.editname.SetFocus()

		# Set sizer for the frame, so we can change frame size to match widgets
		self.windowSizer = wx.BoxSizer()
		self.windowSizer.Add(self.panel, 1, wx.ALL | wx.EXPAND)        

		# Set sizer for the panel content
		self.sizer = wx.GridBagSizer(5, 5)
		self.sizer.Add(self.quote, (0, 0))
		self.sizer.Add(self.result, (0, 1))
		self.sizer.Add(self.lblname, (1, 0))
		self.sizer.Add(self.editname, (1, 1))
		self.sizer.Add(self.button, (2, 0), (1, 2), flag=wx.EXPAND)

		# Set simple sizer for a nice border
		self.border = wx.BoxSizer()
		self.border.Add(self.sizer, 1, wx.ALL | wx.EXPAND, 5)

		# Use the sizers
		self.panel.SetSizerAndFit(self.border)  
		self.SetSizerAndFit(self.windowSizer)  

		# Set event handlers
		self.button.Bind(wx.EVT_BUTTON, self.OnButton)
		self.editname.Bind(wx.EVT_KEY_DOWN,self.parseinfo)

	def OnButton(self, e):
		self.result.SetLabel(self.editname.GetValue())
	
	def parseinfo(self,e):
		keycode = e.GetKeyCode()
		if keycode == wx.WXK_RETURN or keycode == wx.WXK_NUMPAD_ENTER or keycode == wx.WXK_TAB:
			if self.editname.GetValue() == "exit" or self.editname.GetValue() == "exit;":
				exit(0)
			else:
				z = Interpreter(self.editname.GetValue())
				#z.interpret("meee")
				#print interpreter.interpret()
			e.EventObject.Navigate()
		e.Skip()


def main():
	app = wx.App(False)
	frame = WindowFrame(None)
	frame.Show()
	app.MainLoop()

if __name__ == "__main__":
	main()