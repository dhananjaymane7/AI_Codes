import time
import random
from datetime import datetime

responses={
    "hii":["hello","heyyy..!!","ho i can help you"],
    "how are you":["I'm fine","Good"],
    "what is current time?":[datetime.now()],
    "bye":["bye"],
    "default":["Cant understand"]
}
def generate_response(input_text):
    input_text=input_text.lower()
    response=responses.get(input_text,responses["default"])
    return random.choice(response)

def main():
    print("Chatbot it is")
    while True:
        time.sleep(random.uniform(0.5,1.5))
        input_text=input("You :")
        if input_text.lower() == "bye":
            print(generate_response(input_text))
            break
        else:
            print("Bot :",generate_response(input_text))
if __name__ == "__main__":
    main()
