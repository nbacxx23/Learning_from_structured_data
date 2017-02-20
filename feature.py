# -*- coding: utf-8 -*-
from nltk.corpus import treebank
import numpy as np
from collections import Counter
import operator
import string
from sklearn.model_selection import train_test_split
import feature_presentation
import datetime
#train, test = 80% , 20%


#remove '-NONE-'
sentences = treebank.tagged_sents()
new_sentences=[]

for s in sentences:
    sen=[]
    for w in s:
        if w[1] != '-NONE-' :
            sen.append(w)
    new_sentences.append(sen)

train_data, test_data = train_test_split(new_sentences, test_size=0.2)


# initialize the parameters
max_length = 271
max_tag = 45

# stattistiques
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

print dict_word_to_pair['the']



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

word_index,pos_index,pairs_index = data_inf(pairs)

print pos_index






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


print dict_trigram['NNP']


#unitest
new_sentences[0]
sentence = [i[0] for i in new_sentences[0]]
tag = [i[1] for i in new_sentences[0]]
print datetime.datetime.now()
f = feature_presentation.get_feature_vector(position=2,sentence=sentence,tag=',',tag_1='*',tag_2='NNP',word_index =word_index,
    pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
print f
print datetime.datetime.now()
f = feature_presentation.get_feature_vector(position=2,sentence=sentence,tag=',',tag_1='*',tag_2='NNP',word_index =word_index,
    pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
print f
print datetime.datetime.now()
f = feature_presentation.get_feature_vector(position=2,sentence=sentence,tag=',',tag_1='*',tag_2='NNP',word_index =word_index,
    pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
print f
print datetime.datetime.now()
f = feature_presentation.get_feature_vector(position=2,sentence=sentence,tag=',',tag_1='*',tag_2='NNP',word_index =word_index,
    pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
print f
print datetime.datetime.now()


