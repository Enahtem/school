import math


def norm(vec):
   
    sum_of_squares = 0.0  
    for x in vec:
        sum_of_squares += vec[x] * vec[x]
    
    return math.sqrt(sum_of_squares)


def cosine_similarity(vec1, vec2):
    common_keys=set(vec1.keys())&set(vec2.keys())
    if not common_keys:
        return -1
    dot_product = sum(vec1[key] * vec2[key] for key in common_keys)
    magnitude_vec1 = norm(vec1)
    magnitude_vec2 = norm(vec2)
    similarity = dot_product / (magnitude_vec1 * magnitude_vec2)
    return float(similarity)


def build_semantic_descriptors(sentences):
    d={}
    for sentence in sentences:
        for i,word in enumerate(sentence):
            if word not in d:
                d[word]={}
            for neighbor in sentence[:i] + sentence[i+1:]:
                    if neighbor in d[word]:
                        d[word][neighbor] += 1
                    else:
                        d[word][neighbor] = 1
    return d




def build_semantic_descriptors_from_files(filenames):
    descriptors = {}
    for i in range(len(filenames)):
        with open(filenames[i], "r", encoding="latin1") as file_to_read:
            file = file_to_read.read().lower()
            for to_replace in [",", "-", "--", ":", ";", "\n"]:
                file = file.replace(to_replace, " ")
            for to_replace in [".", "!", "?"]:
                file = file.replace(to_replace, ".")
            file = file.split(".")
            file_processed = []
            for sentence in file:
                sentence_processed = [word for word in sentence.split(" ") if word != ""]
                file_processed.append(sentence_processed)
            file_descriptors = build_semantic_descriptors(file_processed)
            for word, neighbors in file_descriptors.items():
                if word in descriptors:
                    for neighbor, count in neighbors.items():
                        if neighbor in descriptors[word]:
                            descriptors[word][neighbor] += count
                        else:
                            descriptors[word][neighbor] = count
                else:
                    descriptors[word] = neighbors
    return descriptors


def most_similar_word(word, choices, semantic_descriptors, similarity_fn):
    max_similarity = -1
    similar_word=""
    for choice in choices:
        similarity = similarity_fn(semantic_descriptors[word], semantic_descriptors[choice])
        if similarity > max_similarity:
            max_similarity = similarity
            similar_word = choice
    return similar_word


def run_similarity_test(filename, semantic_descriptors, similarity_fn):
    percentage = 0
    questions=[]
    with open(filename, "r", encoding="latin1") as file_to_read:
        file=file_to_read.read()
        file = [question for question in file.split("\n") if question != ""]
        for line in file:
            question=line.split(" ")
            questions.append(question)
    for question in questions:
        chosen=most_similar_word(question[0], question[2:], semantic_descriptors, similarity_fn)
        if chosen==question[1]:
            percentage+=1
    percentage/=len(questions)
    return float(percentage)


# sem_descriptors = build_semantic_descriptors_from_files(["wp.txt", "sw.txt"])
# res = run_similarity_test("test.txt", sem_descriptors, cosine_similarity)
# print(res, "of the guesses were correct")
