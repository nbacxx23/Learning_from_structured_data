from nltk.corpus import treebank
import numpy as np
from collections import Counter
import operator
import string
from sklearn.model_selection import train_test_split


#train, test = 80% , 20%


#remove '-NONE-'
sentences = treebank.tagged_sents()
new_sentences=[]
for s in sentences:
    sen=[]
    for w in s:
        if w[1] != '-NONE-':
            sen.append(w)
    new_sentences.append(sen)

train_data, test_data = train_test_split(new_sentences, test_size=0.2)


# initialize the parameters
max_length = 271
max_tag = 46

# stattistiques



#all pairs
pairs = []
for s in train_data:
    for pair in s:
        pairs.append(pair)


#dict for tags corresponding to a word     dict_word_to_pair[word]= set of tags
words = [i[0] for i in pairs]
dict_word_to_pair=dict.fromkeys(words)
for word in dict_word_to_pair:
    dict_word_to_pair[word] = set()
for pair in pairs:
    dict_word_to_pair[pair[0]].add(pair[1])

#make index
def make_index(s):
    dict_s = dict.fromkeys(s)
    k = 0
    for i in dict_s:
        dict_s[i] = k
        k +=1
    return dict_s

def data_inf(data):
    word = set()
    pos = set()
    pairs = set()
    for pair in data:
        word.add(pair[0].lower())
        pos.add(pair[1])
        pairs.add(pair)
    word = make_index(word)
    pos = make_index(pos)
    pairs = make_index(pairs)
    return word,pos,pairs


word_index,pos_index,pairs_index = data_inf(pairs)



#dict for 3-gram, dict_trigram[v]= (w,u)............(all possible (w,u,v))
trigram = set()
for s in new_sentences:
    for i in range(len(s)-2):
        trigram.add((s[i][1],s[i+1][1],s[i+1][1]))
dict_trigram =dict()


for i in pos_index:
    tmp = []
    for tri in trigram:
        if tri[2]==i:
            tmp.append((tri[0],tri[1]))
            dict_trigram[i] = tmp



#feature of word
def presentation_word(word, word_index):
    l = len(word_index)+1
    word_feat = np.zeros(l)
    if word in word_index:
        index = word_index[word]
        word_feat[index] = 1
        word_feat[-1]=1
    else:
        word_feat[-1] = 0
    return word_feat


#feature of tag
def presentation_pos(pos, pos_index):
    l = len(pos_index)+1
    pos_feat = np.zeros(l)
    if pos=='*':
        pos_feat[-1] =1
    else:
        index = pos_index[pos]
        pos_feat[index] = 1
    return pos_feat

#feature of pair
def presentation_pair(pair, pairs_index):
    l = len(pairs_index)
    index = pairs_index[pair]
    pair_feat = np.zeros(l)
    pair_feat[index] = 1
    return pair_feat



#feature of position
def position_feature(position):
    position_feat = np.zeros(max_length)
    position_feat[position] = 1
    return position_feat



#last two words and next two words

def neighbors_word(position,sentence,word_index):
    l = len(word_index)+1
    length_sentence = len(sentence)
    if position==0:
        last_word_feat = np.zeros(l)
        last_two_word_feat = np.zeros(l)
    elif position ==1 :
        last_word_feat = presentation_word(word=sentence[position-1],word_index=word_index)
        last_two_word_feat = np.zeros(l)
    else:
        last_word_feat = presentation_word(word=sentence[position-1],word_index=word_index)
        last_two_word_feat = presentation_word(word=sentence[position-2],word_index=word_index)
    if length_sentence-position==1:
        next_word_feat = np.zeros(l)
        next_two_word_feat = np.zeros(l)
    elif length_sentence-position == 2:
        next_word_feat = presentation_word(word=sentence[position+1],word_index=word_index)
        next_two_word_feat = np.zeros(l)
    else:
        next_word_feat = presentation_word(word=sentence[position+1],word_index=word_index)
        next_two_word_feat = presentation_word(word=sentence[position+2],word_index=word_index)
    return last_word_feat,last_two_word_feat,next_word_feat,next_two_word_feat



dict_words = Counter(words)

s = sorted(dict_words.items(), key=operator.itemgetter(1))
rare_words = []
not_rare_words = []
for i in s:
    if i[1]<2:
        rare_words.append(i[0])
    else:
        not_rare_words.append(i[0])

k = 0
dict_alphabet=dict()
for i in string.ascii_lowercase:
    dict_alphabet[i]=k
    k += 1
dict_alphabet['symbol'] = 26
k = 27
for i in range(10):
    dict_alphabet[str(i)] = k
    k +=1

def prefix_suffix_one(word):
    l = 26+10+1+1
    prefix_one_feat = np.zeros(l)
    suffix_one_feat = np.zeros(l)
    if word[0] not in string.ascii_lowercase and word not in string.digits:
        prefix_one_feat[dict_alphabet['symbol']] = 1 
    else:
        prefix_one_feat[dict_alphabet[word[0]]] = 1
    if word[-1]not in string.ascii_lowercase and word not in string.digits:
        suffix_one_feat[dict_alphabet['symbol']] = 1
    else:
        suffix_one_feat[dict_alphabet[word[-1]]] = 1
    return prefix_one_feat,suffix_one_feat

def hasNumbers(inputString):
    return any(char.isdigit() for char in inputString)

def prefix_suffix_three(word):
    l = 37 * 3
    prefix_three_feat = np.zeros(l)
    suffix_three_feat = np.zeros(l)
    if len(word) == 1:
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol']]=1
            suffix_three_feat[dict_alphabet['symbol']]=1
        else:
            prefix_three_feat[dict_alphabet[word[0]]]=1
            suffix_three_feat[dict_alphabet[word[0]]]=1
    elif len(word) == 2 : 
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol']]=1
        else:
            prefix_three_feat[dict_alphabet[word[0]]] = 1
        if word[1] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol'] + 37] =1
        else:
            prefix_three_feat[dict_alphabet[word[1]]+37] = 1
        if word[-1] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alphabet['symbol']]=1
        else:
            suffix_three_feat[dict_alphabet[word[-1]]]=1
        if word[-2] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alphabet['symbol']+37]=1
        else:
            suffix_three_feat[dict_alphabet[word[-2]]+37]=1
    else:
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol']]=1
        else:
            prefix_three_feat[dict_alphabet[word[0]]] = 1
            
            
        if word[1] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol'] + 37] =1
        else:
            prefix_three_feat[dict_alphabet[word[1]]+37] = 1
            
            
        if word[2] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alphabet['symbol'] + 37+37] =1
        else:
            prefix_three_feat[dict_alphabet[word[2]]+37+37] = 1
            
            
        if word[-1] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alphabet['symbol']]=1
        else:
            suffix_three_feat[dict_alphabet[word[-1]]]=1
        if word[-2] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alphabet['symbol']+37]=1
        else:
            suffix_three_feat[dict_alphabet[word[-2]]+37]=1
        if word[-3] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alphabet['symbol']+37+37]=1
        else:
            suffix_three_feat[dict_alphabet[word[-3]]+37+37]=1
    return prefix_three_feat,suffix_three_feat    


def contain_number(word):
    contain_number_feat = np.zeros(1)
    for i in word:
        if i in string.digits:
            contain_number_feat[0]=1
    return contain_number_feat
def contain_uppercase(word):
    contain_uppercase_feat = np.zeros(1)
    for i in word:
        if i in string.uppercase:
            contain_uppercase_feat[0]=1
    return contain_uppercase_feat

def contain_hyphen(word):
    contain_hyphen_feat = np.zeros(1)
    for i in word:
        if i not in string.digits and i not in string.ascii_lowercase:
            contain_hyphen_feat[0]=1
    return contain_hyphen_feat

def rare_word(word,rare_words,not_rare_words):
    rare_word_feat = np.zeros(3)
    if word in rare_words:
        rare_word_feat[0]=1
    elif word in not_rare_words:
        rare_word_feat[1]=1
    else: 
        rare_word_feat[2] = 1
    return rare_word_feat


#get feature_vector
def get_feature_vector(position,sentence,tag,tag_1,tag_2):
    #word-level features
    word = sentence[position]
    word_feat = presentation_word(word = word, word_index=word_index)
    contain_number_feat = contain_number(word=word)
    contain_uppercase_feat = contain_uppercase(word=word)
    contain_hyphen_feat = contain_hyphen(word=word)
    prefix_feat,suffix_feat = prefix_suffix_three(word=word.lower())
    pair_feat = presentation_pair(pair=(word,tag),pairs_index=pairs_index)
    
    #tag-level features
    tag_feat = presentation_pos(pos=tag, pos_index=pos_index)
    tag_1_feat = presentation_pos(pos=tag_1,pos_index=pos_index)
    tag_2_feat = presentation_pos(pos=tag_2,pos_index=pos_index)
    #position feature
    position_feat = position_feature(position=position)
    last_word_feat,last_two_word_feat,next_word_feat,next_two_word_feat = neighbors_word(position=position,sentence=sentence,word_index=word_index)
    feature_vector = np.concatenate((word_feat,contain_number_feat,contain_uppercase_feat,contain_hyphen_feat,
        prefix_feat,suffix_feat,pair_feat,
        tag_2_feat,tag_1_feat,tag_feat,
        position_feat,last_word_feat,last_two_word_feat,next_word_feat,next_two_word_feat
        ),axis = 0)
    return feature_vector

#unitest
new_sentences[0]
sentence = [i[0] for i in new_sentences[0]]
tag = [i[1] for i in new_sentences[0]]
f = get_feature_vector(position=2,sentence=sentence,tag=',',tag_1='*',tag_2='NNP')
print f
