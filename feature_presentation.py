# -*- coding: utf-8 -*-
"""

@author: Xiaoxiao CHEN/Yuxiang WANG
"""
import string
import numpy as np

max_length = 271
max_tag = 46
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
    pair_feat = np.zeros(l+1)
    if pair in pairs_index:
        index = pairs_index[pair]
        pair_feat[index] = 1
    else:
        pair_feat[-1] = 1
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





def prefix_suffix_one(word,dict_alpha):
    l = 26+10+1+1
    prefix_one_feat = np.zeros(l)
    suffix_one_feat = np.zeros(l)
    if word[0] not in string.ascii_lowercase and word not in string.digits:
        prefix_one_feat[dict_alpha['symbol']] = 1 
    else:
        prefix_one_feat[dict_alpha[word[0]]] = 1
    if word[-1]not in string.ascii_lowercase and word not in string.digits:
        suffix_one_feat[dict_alpha['symbol']] = 1
    else:
        suffix_one_feat[dict_alpha[word[-1]]] = 1
    return prefix_one_feat,suffix_one_feat

def hasNumbers(inputString):
    return any(char.isdigit() for char in inputString)

def prefix_suffix_three(word, dict_alpha):
    l = 37 * 3
    prefix_three_feat = np.zeros(l)
    suffix_three_feat = np.zeros(l)
    if len(word) == 1:
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol']]=1
            suffix_three_feat[dict_alpha['symbol']]=1
        else:
            prefix_three_feat[dict_alpha[word[0]]]=1
            suffix_three_feat[dict_alpha[word[0]]]=1
    elif len(word) == 2 : 
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol']]=1
        else:
            prefix_three_feat[dict_alpha[word[0]]] = 1
        if word[1] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol'] + 37] =1
        else:
            prefix_three_feat[dict_alpha[word[1]]+37] = 1
        if word[-1] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alpha['symbol']]=1
        else:
            suffix_three_feat[dict_alpha[word[-1]]]=1
        if word[-2] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alpha['symbol']+37]=1
        else:
            suffix_three_feat[dict_alpha[word[-2]]+37]=1
    else:
        if word[0] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol']]=1
        else:
            prefix_three_feat[dict_alpha[word[0]]] = 1
            
            
        if word[1] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol'] + 37] =1
        else:
            prefix_three_feat[dict_alpha[word[1]]+37] = 1
            
            
        if word[2] not in string.ascii_lowercase and word not in string.digits:
            prefix_three_feat[dict_alpha['symbol'] + 37+37] =1
        else:
            prefix_three_feat[dict_alpha[word[2]]+37+37] = 1
            
            
        if word[-1] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alpha['symbol']]=1
        else:
            suffix_three_feat[dict_alpha[word[-1]]]=1
        if word[-2] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alpha['symbol']+37]=1
        else:
            suffix_three_feat[dict_alpha[word[-2]]+37]=1
        if word[-3] not in string.ascii_lowercase and word not in string.digits:
            suffix_three_feat[dict_alpha['symbol']+37+37]=1
        else:
            suffix_three_feat[dict_alpha[word[-3]]+37+37]=1
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
def get_feature_vector(position,sentence,tag,tag_1,tag_2,word_index,pos_index,pairs_index, dict_alphabet, rare_words, not_rare_words):
    #word-level features

    word = sentence[position]
    word_feat = presentation_word(word = word, word_index=word_index)
    contain_number_feat = contain_number(word=word)
    contain_uppercase_feat = contain_uppercase(word=word)
    contain_hyphen_feat = contain_hyphen(word=word)
    prefix_feat,suffix_feat = prefix_suffix_three(word=word.lower(),dict_alpha=dict_alphabet)
    pair_feat = presentation_pair(pair=(word,tag),pairs_index=pairs_index)
    rare_word_feat = rare_word(word=word, rare_words= rare_words, not_rare_words= not_rare_words)
    #tag-level features
    tag_feat = presentation_pos(pos=tag, pos_index=pos_index)
    tag_1_feat = presentation_pos(pos=tag_1,pos_index=pos_index)
    tag_2_feat = presentation_pos(pos=tag_2,pos_index=pos_index)
    #position feature
    position_feat = position_feature(position=position)
    last_word_feat,last_two_word_feat,next_word_feat,next_two_word_feat = neighbors_word(position=position,sentence=sentence,word_index=word_index)
    feature_vector = np.concatenate((word_feat,contain_number_feat,contain_uppercase_feat,contain_hyphen_feat,
        prefix_feat,suffix_feat,pair_feat,rare_word_feat,
        tag_2_feat, tag_1_feat,tag_feat,
        position_feat,last_word_feat,last_two_word_feat,next_word_feat,next_two_word_feat
        ),axis = 0)
    return feature_vector
