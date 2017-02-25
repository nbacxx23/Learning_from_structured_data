# -*- coding: utf-8 -*-
"""

@author: Xiaoxiao CHEN/Yuxiang WANG
"""
from __future__ import division
import sys
import math
import copy
from collections import defaultdict
from viterbi import viterbi
from feature_presentation import get_feature_vector 
from nltk.corpus import treebank
import numpy as np
from collections import Counter
import operator
import string
import feature_presentation

add_factor = 1
Words = defaultdict(int)
#phi = defaultdict(int)
alpha = np.ones(61020)
alpha_average = defaultdict(tuple) #(total sum, example number of last update, value of last update)
possible_tags = []

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
    
def get_sentence_and_tags(data):
    sentence = []
    tags = []
    for i in xrange(len(data)):
        sentence.append(str(data[i][0]))
        tags.append(str(data[i][1]))
    return (copy.deepcopy(sentence), copy.deepcopy(tags))

def perceptron(print_alpha,T):    

    f = open("data_train",'r')
    sentence_train = []
    s = []
    for line in f:
        if  line[1:4] == '---':
            sentence_train.append(s)
            s = []
	else :
	    word,tag = line.split('\t')
	    s.append((word,tag[:-1]))
    #print sentence_train

    # initialize the parameters
    max_length = 271
    max_tag = 46

    #all pairs
    pairs = []
    for s in sentence_train:
        for pair in s:
            pairs.append(pair)

    #dict for tags corresponding to a word     dict_word_to_pair[word]= set of tags
    words = [i[0] for i in pairs]
    dict_word_to_pair=dict.fromkeys(words)
    for word in dict_word_to_pair:
        dict_word_to_pair[word] = set()
    for pair in pairs:
        dict_word_to_pair[pair[0]].add(pair[1])


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

    #make index


    #dict for 3-gram, dict_trigram[v]= (w,u)............(all possible (w,u,v))
    trigram = set()
    for s in sentence_train:
        for i in range(len(s)-2):
            trigram.add((s[i][1],s[i+1][1],s[i+2][1]))
    dict_trigram =dict()

    for i in pos_index:
        tmp = []
        for tri in trigram:
            if tri[2]==i:
                tmp.append((tri[0],tri[1]))
                dict_trigram[i] = tmp
    
    
	
    T_DEFAULT = T
    global possible_tags
    global alpha
    global add_factor
    global alpha_sum
    rate = []
    alpha_sum = np.zeros(61020)
    for t in xrange(T_DEFAULT):
        j = 0
	name = 'outputs/iteration_'+str(t)
        name1 = 'outputs/iter_alpha_sum_'+str(t)
	out = open(name, 'w')
        out1 = open(name1, 'w')
	for i in range(len(alpha)):
            out.write('alpha_'+str(i))
	    out.write('\t')
	    out.write(str(alpha[i]))
            out.write('\n')
        out.close()	
        for i in range(len(alpha_sum)):
            out1.write('alpha_sum_'+str(i))
            out1.write('\t')
            out1.write(str(alpha_sum[i]))
            out1.write('\n')
        out1.close()
        correct_number = 0
        wrong_number = 0
        print '---{0}---'.format(t)
        sys.stdout.flush()
        dont_repeat = True
        sentence =[i[0] for i in sentence_train[5]]
        tags = viterbi(sentence,alpha,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words,dict_word_to_pair,dict_trigram)
        for s in xrange(len(sentence_train)):
            data = sentence_train[s]
            vals = get_sentence_and_tags(data)
            
            examp_num = s+1
            sentence = vals[0]
            correct_tags = vals[1]
            #get prediction tags by viterbi
            tags = viterbi(sentence,alpha,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words,dict_word_to_pair,dict_trigram)
            indices = get_global_phi(sentence, tags,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words)
            #print max(alpha),min(alpha)
            correct_indices = get_global_phi(sentence, correct_tags,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words)
            #print np.sum(alpha)
            error = np.zeros(61020)
            #update the alpha
            for i in range(len(error)):
                if indices[i]!=correct_indices[i]:
                    error[i] = correct_indices[i]-indices[i]

            for i in range(len(tags)):
                if tags[i]==correct_tags[i]:
                    correct_number +=1
                else:
                    wrong_number +=1
            if not tags == correct_tags:
                dont_repeat = False
                alpha = alpha + error
            else:
                j=j+1
            alpha_sum = alpha_sum + alpha
        if dont_repeat:
            print 'SUCCESS!!!'
            break
        
        
        rate.append(wrong_number/(wrong_number+correct_number))
    out3 = open('rate', 'w')
    for i in rate:
        out3.write(str(i))
        out3.write('\n')
    out3.close()

        #if print_alpha:
         #   write_alpha(t)
        
def write_alpha(t):
    global alpha_average
    string = 'outputs/alpha_{0}.txt'.format(t)
    out = open(string, 'w')
    for i in alpha_average:
        out.write('{0} {1}\n'.format(i, alpha_average[i][0]))
    out.close()

def get_global_phi(sentence, tags,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words):
    result = np.zeros(61020)
    if len(sentence) == 1:
        d = dict(w_i = sentence[0],t_2 = '*', t_1 = '*', t = tags[0])
        result += get_feature_vector(0,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
    elif len(sentence) == 2:
        d = dict(w_i = sentence[0],t_2 = '*', t_1 = '*', t = tags[0])
        result += get_feature_vector(0,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
        d = dict(w_i = sentence[1],t_2 = '*', t_1 = tags[0],t = tags[1])
        result += get_feature_vector(1,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
    else:
        for i in range(len(sentence)):
        ##########Strings, trigram model############
            if i == 0:
                d = dict(w_i = sentence[0], t_2 = '*', t_1 = '*', t = tags[0])
                result += get_feature_vector(i,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
            elif i == 1:
                d = dict(w_i = sentence[1], t_2 = '*', t_1 = tags[0], t = tags[1])
                result += get_feature_vector(i,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
            else:
                d = dict(w_i = sentence[i], t_2 = tags[i-2], t_1 = tags[i-1], t = tags[i])
                result += get_feature_vector(i,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)    
    return copy.deepcopy(result)
	
if __name__ == '__main__':    
    perceptron(1,100)
