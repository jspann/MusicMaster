#this is where the command parsing takes place
import player
import thread

commands = ["stop","load"]
mathfunc = ["sin","cos"]
variables = []
class Interpreter:
	def __init__(self):
		pass

	def parse(self,text):
		mystr = ""
		isString = False # only true when we are in a string
		for l in range(len(text)):
			if text[l] == " ":
				pass
			elif text[l] == ".":
				pass
			elif text[l] == "=":
				checkStr(mystr)
				mystr = ""
			elif l == len(text)-1:
				#last character
			else:
				mystr = mystr + text[l]
			print text[l]
		player.loop("trapbeat.wav")
		return 6
		
	def checkStr(mystring):
		if mystring in commands:
			pass
		elif
