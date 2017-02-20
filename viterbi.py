# -*- coding: utf-8 -*-
"""

@author: Xiaoxiao CHEN/Yuxiang WANG
"""
import math
import copy
import numpy as np
from collections import defaultdict
from feature_presentation import get_feature_vector  

pi = defaultdict(int)
bp = defaultdict(tuple)

def viterbi(sentence,alpha,word_index,pos_index , pairs_index, dict_alphabet, rare_words, not_rare_words,dict_word_to_pair,dict_trigram):
    pi.clear()
    bp.clear()
    pi[(0, '*', '*')] = 1.0
    if len(sentence) == 1:
        v_tags = dict_word_to_pair[sentence[0]]
        val_max = 0
        for v in v_tags:
            d = dict(w_i = sentence[0],t_2 = '*',t_1='*',t=v)
            phi = get_feature_vector(0,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
            val = np.sum(alpha*phi)
            if val>val_max:
                val_max=val
                result_tags = [v]
        return result_tags
    elif len(sentence) == 2:
        v_tags = dict_word_to_pair[sentence[0]]
        val_max = 0
        for v in v_tags:
            d = dict(w_i = sentence[0],t_2 = '*',t_1='*',t=v)
            phi = get_feature_vector(0,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
            val = np.sum(alpha*phi)
            if val>val_max:
                val_max=val
                result_tags = [v]
        v2_tags = dict_word_to_pair[sentence[1]]
        val1 =val
        val_max = val
        for v2 in v2_tags:
            d = dict(w_i = sentence[1],t_2 = '*',t_1 =v,t=v2)
            phi = get_feature_vector(1,sentence, d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
            val = np.sum(alpha*phi)+val1
            if val> val_max:
                val_max = val
                result_tags.append(v2)
        return result_tags
    else:
        for k in range(1,len(sentence)+1):
            t = dict_word_to_pair[sentence[k-1]]
            if k >2:
                t2 = dict_word_to_pair[sentence[k-3]]
            
                t1 = dict_word_to_pair[sentence[k-2]]
                
            if k == 1:
                t1 = ['*']
                t2 = ['*']

            if k == 2:
                t2 = ['*']
            for u in t1:
                for v in t:
                    
                    for w in t2:
                        pi_val = pi.get((k-1,w,u), 0.5)
                        
                        d = dict(w_i = sentence[k-1], t_2 = w, t_1 = u, t = v)
                        phi = get_feature_vector(k-1,sentence,d['t'], d['t_1'],d['t_2'],word_index =word_index,
        pos_index=pos_index , pairs_index=pairs_index , dict_alphabet=dict_alphabet, rare_words=rare_words, not_rare_words=not_rare_words)
                        val = pi_val+np.sum(alpha*phi)
                        test = pi.get((k,u,v), 0.5)
                        if test == 0.5 or val > test:
                            pi[(k,u,v)] = val
                            bp[(k,u,v)] = w

    result_tags = []
    result_val = 0
    max_tmp = 0

    for (k, u, v) in bp:
        if k == len(sentence):
            if pi[(k,u,v)] >max_tmp:
                max_tmp = pi[(k,u,v)]
                w = bp[(k,u,v)]
                last = v 
                last_two = u
                last_three = w
    result_tags.append(last)

    result_tags.append(last_two)

    result_tags.append(last_three)

    for k in range(len(sentence)-2, 1, -1):
        t = bp[(k+1, result_tags[len(result_tags)-1], result_tags[len(result_tags)-2])]
        result_tags.append(t)
    result_tags.reverse()
    while result_tags[0] == '*':
        result_tags.reverse()
        result_tags.pop()
        result_tags.reverse()
    return copy.deepcopy(result_tags)