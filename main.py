#this file is for the interface
import wx
import sys
import wave
import math
import struct
import random
import argparse
import thread
import json

from Interpreter import Interpreter
from multiprocessing import Process

class WindowFrame(wx.Frame):
	def __init__(self, parent):
		wx.Frame.__init__(self, parent)
		#load json
		with open('style.json') as data_file:    
			data = json.load(data_file)
		self.SetTitle('Music Master')
		self.SetSize((data['window-width'], data['window-height']))
		self.panel = wx.Panel(self)



		self.editname = wx.TextCtrl(self.panel, size=(240, -1), style=wx.TE_PROCESS_ENTER)
		self.editname.Bind(wx.EVT_KEY_DOWN,self.parseinfo)




	def OnQuit(self, e):
		self.Close()
	
	def parseinfo(self,e):
		keycode = e.GetKeyCode()
		if keycode == wx.WXK_RETURN or keycode == wx.WXK_NUMPAD_ENTER or keycode == wx.WXK_TAB:
			if self.editname.GetValue() == "exit" or self.editname.GetValue() == "exit;":
				exit(0)
			else:
				z = Interpreter()
				#thread.start_new_thread(z.parse(self.editname.GetValue()))
				z.parse(self.editname.GetValue())
			e.EventObject.Navigate()
		e.Skip()

def main():
	try:
		import pyaudio
	except Exception, e:
		print "seems like you don't have pyaudio. Check out the instructions here: https://gist.github.com/jiaaro/9767512210a1d80a8a0d"
		exit(0)
	app = wx.App(False)
	frame = WindowFrame(None)
	frame.Show()
	app.MainLoop()

if __name__ == "__main__":
	main()