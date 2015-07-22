#this is where the command parsing takes place
import player
import thread
import threading

commands = ["new","play","load","loadf","clear","stopall"]
mathfunc = ["sin","cos"]
variables = []
listen_t = threading.Thread(target=player.loop, args=("trapbeat.wav", ))
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
				listen_t.start()
				#http://stackoverflow.com/questions/16734534/close-listening-socket-in-python-thread
				#self.checkStr(mystr)
				mystr = ""
			elif text[l] == "\'":
				isString = not isString
			elif l == len(text)-1:
				#last character
				pass
			else:
				mystr = mystr + text[l]
			print text[l]
		#player.loop("trapbeat.wav")
		return 6

	def checkStr(self,mystring):
		if mystring in commands:
			listen_t.start()
		elif mystring in variables:
			pass
		else:
			variables.append(mystring)
			listen_t.stop()