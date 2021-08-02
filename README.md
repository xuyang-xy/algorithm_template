# algorithm_template

DeepFM Feature
1   old_tr
...
24  matchrank
25  matchrank_key
26  matchrank_normal
27  (extra_rank & 0xFF)
28  (extra_rank & 0xFF0000) >> 16
29  (extra_rank & 0xFF000000) >> 24
30  (mrfrank & 0x0000FFFF)/1000.0f
31  keybmrank
32  key_bm25
33  kcrank
34  bm25
35  userrank
...
121 zh_ans_up
122 zh_reply_num
123 ans_len
124 zh_has_more
125 zh_answer_num
...
195 prerank_input->region_weight,//地域性意图
196 _pdc->query_intent_info.med_intent_tags,//医疗意图
197 prerank_input->health_new_weight,//医疗意图
198 prerank_input->query_baike_intent,//百科意图
199 prerank_input->ofc_weight,//官网意图
...
```python
self.pos_vec = model.inference(pos_input)
self.neg_vec = model.inference(pos_input)
self.diff_vec = sigmod(pos_vec - neg_vec)
self.loss = log_loss(label, deff_vec)
```

```cpp
naturexgb_score = getScore()
if ()
```