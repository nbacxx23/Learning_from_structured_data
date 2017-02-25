# -*- coding: utf-8 -*-
"""
This class is applied to test the final model after training.
Since the train set and test set are predefined
at first, we use this class to input test data and evaluate
the performances of the trained parameters. It
uses all the necessary information from the train set
to narrow down the search space. Then we implement
directly the parameters and use viterbi algorithm
to decode all the sentences and compare them to the
correct tag sequences. Finally we can get an error rate
curve of different parameters.

@author: xichen
"""
from __future__ import division
from viterbi import viterbi
from perceptron import get_sentence_and_tags
import numpy as np
from collections import Counter
import operator
import string
import perceptron
import matplotlib.pyplot as plt

def test(alpha_in):
    alpha = np.zeros(61020)
    if alpha_in == 'last':
        f = open("iteration_34","r")
        i = 0
        for line in f:
            alpha[i] = line.split('\t')[-1]
            i +=1
    elif alpha_in == 'average':
        f = open("iter_alpha_sum_34","r")
        i = 0
        for line in f:
            alpha[i] = line.split('\t')[-1]
            i+=1
        alpha = alpha/(35*3131)
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


    #all pairs
    pairs = []
    for s in sentence_train:
        for pair in s:
            pairs.append(pair)

    #dict for tags corresponding to a word     dict_word_to_pair[word]= set of tags
    words = [k[0] for k in pairs]
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

    word_index,pos_index,pairs_index = perceptron.data_inf(pairs)

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

    f = open("data_test",'r')
    sentence_test = []
    s = []
    for line in f:
        if  line[1:4] == '---':
            sentence_test.append(s)
            s = []
	else :
		word,tag = line.split('\t')
		s.append((word,tag[:-1]))
    
    '''
    Main test part,no need to get big phi compared to perceptron, just compare the tags and get the error rate 
    '''
    tot = 0
    error = 0
    error_list = []
    num_sen = []
    for s in xrange(len(sentence_test)):
            data = sentence_test[s]
            vals = get_sentence_and_tags(data)
            sentence = vals[0]
            print "len:",len(sentence)
            
            correct_tags = vals[1]
            tags = viterbi(sentence,alpha,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words,dict_word_to_pair,dict_trigram)
            
            for i,j in zip(tags,correct_tags):
                if i!=j:
                    error+=1
                tot +=1
            error_rate = error/tot
            print "error:",error
            print "tot:",tot
            print "error rate:",error_rate
            num_sen.append(s+1)
            error_list.append(error_rate)
    print "error rate: ", error_rate
    
    #plot the test error curve
    plt.plot(num_sen,error_list,color="blue")
    plt.xlabel('Number of sentences')
    plt.ylabel('Error rate')
    plt.title("Error rate convergence of avg - 35 iterations")
    plt.savefig("35_avg.png")
    plt.show()
    
if __name__ == '__main__':
    alpha = 'average'    
    test(alpha)