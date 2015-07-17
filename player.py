#this is where code execution takes placs
import wave
import pyaudio
import sys
import thread

CHUNK = 1024

def play(filename):
	wf = wave.open(filename, 'rb')

	p = pyaudio.PyAudio()

	stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
					channels=wf.getnchannels(),
					rate=wf.getframerate(),
					output=True)

	data = wf.readframes(CHUNK)

	while data != '':
		stream.write(data)
		data = wf.readframes(CHUNK)

	stream.stop_stream()
	stream.close()

	p.terminate()

def loop(filename):
	wf = wave.open(filename, 'rb')

	p = pyaudio.PyAudio()

	stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
					channels=wf.getnchannels(),
					rate=wf.getframerate(),
					output=True)

	data = wf.readframes(CHUNK)
	while True:
		stream.write(data)
		data = wf.readframes(CHUNK)
		if data == '' : # If file is over then rewind.
			wf.rewind()
			data = wf.readframes(CHUNK)