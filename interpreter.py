commands = ["stop","load"]
class Interpreter:
	def __init__(self,z):
		print z
		self.z = z

	def parse(self,text):
		print text
		return 6