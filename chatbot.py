import random
import time
from datetime import datetime
responses = {
    "hi": ["Hello!", "Hi there!", "Hey! How can I help you today?"],
    "how are you": ["I'm good, thanks for asking!", "I'm doing well, how about you?"],
    "bye": ["Goodbye!", "See you later!", "Take care!"],
    "what is current time?":[datetime.now()],
    "thank you": ["You're welcome!", "No problem!", "Anytime!"],
    "default": ["I'm sorry, I didn't understand that.", "Could you please rephrase that?", "I'm still learning, could you try again?"],
}
def generate_response(user_input):
    user_input = user_input.lower()
    response = responses.get(user_input, responses["default"])  
    return random.choice(response) 
def main():
    print("Welcome to ChatBot! Type 'bye' to exit.")
    while True:
        user_input = input("You: ")
        time.sleep(random.uniform(0.5, 1.5))
        if user_input.lower() == 'bye':
            print(generate_response(user_input))
            break
        else:
            print("Bot:", generate_response(user_input))
if __name__ == "__main__":
    main()
