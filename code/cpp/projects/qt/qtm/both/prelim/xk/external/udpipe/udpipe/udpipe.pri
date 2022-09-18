
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = udpipe

include(../build-group.pri)

#TEMPLATE = app

#DEFINES += DEFAULT_KPH_FOLDER=\\\"$$CPP_ROOT_DIR/kph\\\"

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


INCLUDEPATH += $$KAUVIR_PHAON_SRC_GROUP_DIR
INCLUDEPATH += $$KAUVIR_KCM_SRC_GROUP_DIR
INCLUDEPATH += $$QHYP_SRC_GROUP_DIR
INCLUDEPATH += $$KCM_RUNTIME_EVAL_SRC_GROUP_DIR
INCLUDEPATH += $$KAUVIR_RUNTIME_SRC_GROUP_DIR

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR


CONFIG += no_keywords


DEFINES += USE_KANS


INCLUDEPATH += $$SRC_GROUP_DIR/udpipe $$SRC_GROUP_DIR/

HEADERS += \
    $$SRC_DIR/model/evaluator.h \
    $$SRC_DIR/model/model.h \
    $$SRC_DIR/model/model_morphodita_parsito.h \
    $$SRC_DIR/model/pipeline.h \
    $$SRC_DIR/morphodita/derivator/derivation_formatter.h \
    $$SRC_DIR/morphodita/derivator/derivator.h \
    $$SRC_DIR/morphodita/derivator/derivator_dictionary.h \
    $$SRC_DIR/morphodita/derivator/derivator_dictionary_encoder.h \
    $$SRC_DIR/morphodita/morpho/casing_variants.h \
    $$SRC_DIR/morphodita/morpho/czech_lemma_addinfo.h \
    $$SRC_DIR/morphodita/morpho/czech_morpho.h \
    $$SRC_DIR/morphodita/morpho/czech_morpho_encoder.h \
    $$SRC_DIR/morphodita/morpho/english_lemma_addinfo.h \
    $$SRC_DIR/morphodita/morpho/english_morpho.h \
    $$SRC_DIR/morphodita/morpho/english_morpho_encoder.h \
    $$SRC_DIR/morphodita/morpho/english_morpho_guesser.h \
    $$SRC_DIR/morphodita/morpho/english_morpho_guesser.rl \
    $$SRC_DIR/morphodita/morpho/english_morpho_guesser_encoder.h \
    $$SRC_DIR/morphodita/morpho/external_morpho.h \
    $$SRC_DIR/morphodita/morpho/external_morpho_encoder.h \
    $$SRC_DIR/morphodita/morpho/generic_lemma_addinfo.h \
    $$SRC_DIR/morphodita/morpho/generic_morpho.h \
    $$SRC_DIR/morphodita/morpho/generic_morpho_encoder.h \
    $$SRC_DIR/morphodita/morpho/morpho.h \
    $$SRC_DIR/morphodita/morpho/morpho_dictionary.h \
    $$SRC_DIR/morphodita/morpho/morpho_dictionary_encoder.h \
    $$SRC_DIR/morphodita/morpho/morpho_ids.h \
    $$SRC_DIR/morphodita/morpho/morpho_prefix_guesser.h \
    $$SRC_DIR/morphodita/morpho/morpho_prefix_guesser_encoder.h \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser.h \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser_encoder.h \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser_trainer.h \
    $$SRC_DIR/morphodita/morpho/persistent_unordered_map.h \
    $$SRC_DIR/morphodita/morpho/persistent_unordered_map_encoder.h \
    $$SRC_DIR/morphodita/morpho/raw_morpho_dictionary_reader.h \
    $$SRC_DIR/morphodita/morpho/small_stringops.h \
    $$SRC_DIR/morphodita/morpho/tag_filter.h \
    $$SRC_DIR/morphodita/tagger/conllu_elementary_features.h \
    $$SRC_DIR/morphodita/tagger/czech_elementary_features.h \
    $$SRC_DIR/morphodita/tagger/elementary_features.h \
    $$SRC_DIR/morphodita/tagger/elementary_features_encoder.h \
    $$SRC_DIR/morphodita/tagger/feature_sequences.h \
    $$SRC_DIR/morphodita/tagger/feature_sequences_encoder.h \
    $$SRC_DIR/morphodita/tagger/feature_sequences_optimizer.h \
    $$SRC_DIR/morphodita/tagger/generic_elementary_features.h \
    $$SRC_DIR/morphodita/tagger/perceptron_tagger.h \
    $$SRC_DIR/morphodita/tagger/perceptron_tagger_trainer.h \
    $$SRC_DIR/morphodita/tagger/tagger.h \
    $$SRC_DIR/morphodita/tagger/tagger_ids.h \
    $$SRC_DIR/morphodita/tagger/tagger_trainer.h \
    $$SRC_DIR/morphodita/tagger/training_maps.h \
    $$SRC_DIR/morphodita/tagger/viterbi.h \
    $$SRC_DIR/morphodita/tagger/vli.h \
    $$SRC_DIR/morphodita/tagset_converter/identity_tagset_converter.h \
    $$SRC_DIR/morphodita/tagset_converter/pdt_to_conll2009_tagset_converter.h \
    $$SRC_DIR/morphodita/tagset_converter/strip_lemma_comment_tagset_converter.h \
    $$SRC_DIR/morphodita/tagset_converter/strip_lemma_id_tagset_converter.h \
    $$SRC_DIR/morphodita/tagset_converter/tagset_converter.h \
    $$SRC_DIR/morphodita/tokenizer/czech_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/czech_tokenizer.rl \
    $$SRC_DIR/morphodita/tokenizer/english_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/english_tokenizer.rl \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer.rl \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer_factory.h \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer_factory_encoder.h \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_factory.h \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_network.h \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_network_trainer.h \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_trainer.h \
    $$SRC_DIR/morphodita/tokenizer/ragel_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/ragel_tokenizer.rl \
    $$SRC_DIR/morphodita/tokenizer/tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/tokenizer_factory.h \
    $$SRC_DIR/morphodita/tokenizer/tokenizer_ids.h \
    $$SRC_DIR/morphodita/tokenizer/unicode_tokenizer.h \
    $$SRC_DIR/morphodita/tokenizer/vertical_tokenizer.h \
    $$SRC_DIR/morphodita/version/version.h \
    $$SRC_DIR/parsito/configuration/configuration.h \
    $$SRC_DIR/parsito/configuration/node_extractor.h \
    $$SRC_DIR/parsito/configuration/value_extractor.h \
    $$SRC_DIR/parsito/embedding/embedding.h \
    $$SRC_DIR/parsito/network/activation_function.h \
    $$SRC_DIR/parsito/network/network_parameters.h \
    $$SRC_DIR/parsito/network/neural_network.h \
    $$SRC_DIR/parsito/network/neural_network_trainer.h \
    $$SRC_DIR/parsito/parser/parser.h \
    $$SRC_DIR/parsito/parser/parser_nn.h \
    $$SRC_DIR/parsito/parser/parser_nn_trainer.h \
    $$SRC_DIR/parsito/transition/transition.h \
    $$SRC_DIR/parsito/transition/transition_oracle.h \
    $$SRC_DIR/parsito/transition/transition_system.h \
    $$SRC_DIR/parsito/transition/transition_system_link2.h \
    $$SRC_DIR/parsito/transition/transition_system_projective.h \
    $$SRC_DIR/parsito/transition/transition_system_swap.h \
    $$SRC_DIR/parsito/tree/node.h \
    $$SRC_DIR/parsito/tree/tree.h \
    $$SRC_DIR/parsito/tree/tree_format.h \
    $$SRC_DIR/parsito/tree/tree_format_conllu.h \
    $$SRC_DIR/parsito/version/version.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/autoinit_funcs.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/connection.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/internal.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/memorypool.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/MHD_config.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/microhttpd.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/platform.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/platform_interface.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/reason_phrase.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/response.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/tsearch.h \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/w32functions.h \
    $$SRC_DIR/rest_server/microrestd/pugixml/pugiconfig.h \
    $$SRC_DIR/rest_server/microrestd/pugixml/pugixml.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/json_builder.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/json_response_generator.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/response_generator.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/rest_request.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/rest_server.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/rest_service.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/string_piece.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/version.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/xml_builder.h \
    $$SRC_DIR/rest_server/microrestd/rest_server/xml_response_generator.h \
    $$SRC_DIR/rest_server/microrestd/microrestd.h \
    $$SRC_DIR/rest_server/microrestd/pugixml.h \
    $$SRC_DIR/rest_server/udpipe_service.h \
    $$SRC_DIR/sentence/empty_node.h \
    $$SRC_DIR/sentence/input_format.h \
    $$SRC_DIR/sentence/multiword_token.h \
    $$SRC_DIR/sentence/output_format.h \
    $$SRC_DIR/sentence/sentence.h \
    $$SRC_DIR/sentence/token.h \
    $$SRC_DIR/sentence/word.h \
    $$SRC_DIR/tokenizer/detokenizer.h \
    $$SRC_DIR/tokenizer/morphodita_tokenizer_wrapper.h \
    $$SRC_DIR/tokenizer/multiword_splitter.h \
    $$SRC_DIR/tokenizer/multiword_splitter_trainer.h \
    $$SRC_DIR/trainer/trainer.h \
    $$SRC_DIR/trainer/trainer_morphodita_parsito.h \
    $$SRC_DIR/trainer/training_failure.h \
    $$SRC_DIR/unilib/unicode.h \
    $$SRC_DIR/unilib/uninorms.h \
    $$SRC_DIR/unilib/unistrip.h \
    $$SRC_DIR/unilib/utf16.h \
    $$SRC_DIR/unilib/utf8.h \
    $$SRC_DIR/unilib/version.h \
    $$SRC_DIR/utils/binary_decoder.h \
    $$SRC_DIR/utils/binary_encoder.h \
    $$SRC_DIR/utils/common.h \
    $$SRC_DIR/utils/compressor.h \
    $$SRC_DIR/utils/getpara.h \
    $$SRC_DIR/utils/getwhole.h \
    $$SRC_DIR/utils/iostreams.h \
    $$SRC_DIR/utils/named_values.h \
    $$SRC_DIR/utils/new_unique_ptr.h \
    $$SRC_DIR/utils/options.h \
    $$SRC_DIR/utils/parse_double.h \
    $$SRC_DIR/utils/parse_int.h \
    $$SRC_DIR/utils/pointer_decoder.h \
    $$SRC_DIR/utils/process_args.h \
    $$SRC_DIR/utils/run_process.h \
    $$SRC_DIR/utils/split.h \
    $$SRC_DIR/utils/string_piece.h \
    $$SRC_DIR/utils/threadsafe_resource_loader.h \
    $$SRC_DIR/utils/threadsafe_stack.h \
    $$SRC_DIR/utils/unaligned_access.h \
    $$SRC_DIR/utils/url_detector.h \
    $$SRC_DIR/utils/xml_encoded.h \
    $$SRC_DIR/version/version.h \
    $$SRC_DIR/common.h \
    $$SRC_DIR/udpipe.h


SOURCES += \
    $$SRC_DIR/model/evaluator.cpp \
    $$SRC_DIR/model/model.cpp \
    $$SRC_DIR/model/model_morphodita_parsito.cpp \
    $$SRC_DIR/model/pipeline.cpp \
    $$SRC_DIR/morphodita/derivator/derivation_formatter.cpp \
    $$SRC_DIR/morphodita/derivator/derivator_dictionary.cpp \
    $$SRC_DIR/morphodita/derivator/derivator_dictionary_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/czech_morpho.cpp \
    $$SRC_DIR/morphodita/morpho/czech_morpho_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/english_morpho.cpp \
    $$SRC_DIR/morphodita/morpho/english_morpho_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/english_morpho_guesser.cpp \
    $$SRC_DIR/morphodita/morpho/english_morpho_guesser_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/external_morpho.cpp \
    $$SRC_DIR/morphodita/morpho/external_morpho_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/generic_morpho.cpp \
    $$SRC_DIR/morphodita/morpho/generic_morpho_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/morpho.cpp \
    $$SRC_DIR/morphodita/morpho/morpho_prefix_guesser_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser.cpp \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser_encoder.cpp \
    $$SRC_DIR/morphodita/morpho/morpho_statistical_guesser_trainer.cpp \
    $$SRC_DIR/morphodita/morpho/raw_morpho_dictionary_reader.cpp \
    $$SRC_DIR/morphodita/morpho/tag_filter.cpp \
    $$SRC_DIR/morphodita/tagger/tagger.cpp \
    $$SRC_DIR/morphodita/tagset_converter/identity_tagset_converter.cpp \
    $$SRC_DIR/morphodita/tagset_converter/pdt_to_conll2009_tagset_converter.cpp \
    $$SRC_DIR/morphodita/tagset_converter/strip_lemma_comment_tagset_converter.cpp \
    $$SRC_DIR/morphodita/tagset_converter/strip_lemma_id_tagset_converter.cpp \
    $$SRC_DIR/morphodita/tagset_converter/tagset_converter.cpp \
    $$SRC_DIR/morphodita/tokenizer/czech_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/english_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer_factory.cpp \
    $$SRC_DIR/morphodita/tokenizer/generic_tokenizer_factory_encoder.cpp \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_factory.cpp \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_network.cpp \
    $$SRC_DIR/morphodita/tokenizer/gru_tokenizer_trainer.cpp \
    $$SRC_DIR/morphodita/tokenizer/ragel_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/tokenizer_factory.cpp \
    $$SRC_DIR/morphodita/tokenizer/unicode_tokenizer.cpp \
    $$SRC_DIR/morphodita/tokenizer/vertical_tokenizer.cpp \
    $$SRC_DIR/morphodita/version/morphodita-version.cpp \
    $$SRC_DIR/parsito/configuration/configuration.cpp \
    $$SRC_DIR/parsito/configuration/node_extractor.cpp \
    $$SRC_DIR/parsito/configuration/value_extractor.cpp \
    $$SRC_DIR/parsito/embedding/embedding.cpp \
    $$SRC_DIR/parsito/embedding/embedding_encode.cpp \
    $$SRC_DIR/parsito/network/neural_network.cpp \
    $$SRC_DIR/parsito/network/neural_network_trainer.cpp \
    $$SRC_DIR/parsito/parser/parser.cpp \
    $$SRC_DIR/parsito/parser/parser_nn.cpp \
    $$SRC_DIR/parsito/parser/parser_nn_trainer.cpp \
    $$SRC_DIR/parsito/transition/transition.cpp \
    $$SRC_DIR/parsito/transition/transition_system.cpp \
    $$SRC_DIR/parsito/transition/transition_system_link2.cpp \
    $$SRC_DIR/parsito/transition/transition_system_projective.cpp \
    $$SRC_DIR/parsito/transition/transition_system_swap.cpp \
    $$SRC_DIR/parsito/tree/tree.cpp \
    $$SRC_DIR/parsito/tree/tree_format.cpp \
    $$SRC_DIR/parsito/tree/tree_format_conllu.cpp \
    $$SRC_DIR/parsito/version/parsito-version.cpp \
    \#$$SRC_DIR/rest_server/microrestd/libmicrohttpd/connection.cpp \
    \#$$SRC_DIR/rest_server/microrestd/libmicrohttpd/daemon.cpp \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/internal.cpp \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/memorypool.cpp \
    \#$$SRC_DIR/rest_server/microrestd/libmicrohttpd/postprocessor.cpp \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/reason_phrase.cpp \
    $$SRC_DIR/rest_server/microrestd/libmicrohttpd/response.cpp \
    \#$$SRC_DIR/rest_server/microrestd/libmicrohttpd/w32functions.cpp \
    $$SRC_DIR/rest_server/microrestd/pugixml/pugixml.cpp \
    $$SRC_DIR/rest_server/microrestd/rest_server/json_builder.cpp \
    $$SRC_DIR/rest_server/microrestd/rest_server/json_response_generator.cpp \
    \#$$SRC_DIR/rest_server/microrestd/rest_server/rest_server.cpp \
    \#$$SRC_DIR/rest_server/microrestd/rest_server/version.cpp \
    $$SRC_DIR/rest_server/microrestd/rest_server/xml_builder.cpp \
    $$SRC_DIR/rest_server/microrestd/rest_server/xml_response_generator.cpp \
    \#$$SRC_DIR/rest_server/udpipe_server.cpp \
    $$SRC_DIR/rest_server/udpipe_service.cpp \
    $$SRC_DIR/sentence/input_format.cpp \
    $$SRC_DIR/sentence/output_format.cpp \
    $$SRC_DIR/sentence/sentence.cpp \
    $$SRC_DIR/sentence/token.cpp \
    $$SRC_DIR/tokenizer/detokenizer.cpp \
    $$SRC_DIR/tokenizer/morphodita_tokenizer_wrapper.cpp \
    $$SRC_DIR/tokenizer/multiword_splitter.cpp \
    $$SRC_DIR/tokenizer/multiword_splitter_trainer.cpp \
    $$SRC_DIR/trainer/trainer.cpp \
    $$SRC_DIR/trainer/trainer_morphodita_parsito.cpp \
    $$SRC_DIR/trainer/training_failure.cpp \
    $$SRC_DIR/unilib/unicode.cpp \
    $$SRC_DIR/unilib/uninorms.cpp \
    $$SRC_DIR/unilib/unistrip.cpp \
    $$SRC_DIR/unilib/utf16.cpp \
    $$SRC_DIR/unilib/utf8.cpp \
    $$SRC_DIR/unilib/unilib-version.cpp \
    $$SRC_DIR/utils/compressor_load.cpp \
    $$SRC_DIR/utils/compressor_save.cpp \
    $$SRC_DIR/utils/options.cpp \
    $$SRC_DIR/utils/url_detector.cpp \
    $$SRC_DIR/version/version.cpp \
    $$SRC_DIR/udpipe.cpp



#LIBS += -L$$TARGETSDIR -ludpipe #-ldygred-sentence -lqring

