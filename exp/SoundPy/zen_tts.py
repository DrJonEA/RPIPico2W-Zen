#!/usr/bin/env python3
import argparse
from google.cloud import texttospeech

def synthesize_zen_style(
    text: str,
    output_path: str = "zen_output.wav",
    language_code: str = "en-GB",
    voice_name: str | None = None,
    speaking_rate: float = 0.7,
    pitch: float = -2.5
) -> None:
    client = texttospeech.TextToSpeechClient()

    # Voice selection: try a British, neutral voice (tweak name later if you like)
    voice_params = {
        "language_code": language_code,
        #"ssml_gender": texttospeech.SsmlVoiceGender.NEUTRAL,
    }
    if voice_name:
        voice_params["name"] = voice_name

    voice = texttospeech.VoiceSelectionParams(**voice_params)

    # Audio config: linear16 = WAV/PCM, slower, slightly lower pitch for “calm computer”
    audio_config = texttospeech.AudioConfig(
        audio_encoding=texttospeech.AudioEncoding.LINEAR16,
        speaking_rate=speaking_rate,
        pitch=pitch,
    )

    synthesis_input = texttospeech.SynthesisInput(text=text)

    response = client.synthesize_speech(
        input=synthesis_input,
        voice=voice,
        audio_config=audio_config,
    )

    with open(output_path, "wb") as out:
        out.write(response.audio_content)
    print(f"Saved Zen-style audio to {output_path}")


def main():
    parser = argparse.ArgumentParser(
        description="Generate Zen-from-Blake's-7-style TTS using Google Cloud Text-to-Speech."
    )
    parser.add_argument(
        "--text",
        type=str,
        help="Text to speak. If omitted, --text-file must be provided.",
    )
    parser.add_argument(
        "--text-file",
        type=str,
        help="Path to a text file to read from.",
    )
    parser.add_argument(
        "--out",
        type=str,
        default="zen_output.wav",
        help="Output WAV file path.",
    )
    parser.add_argument(
        "--voice-name",
        type=str,
        default=None,
        help="Optional specific GCP voice name (e.g. en-GB-Neural2-A).",
    )
    parser.add_argument(
        "--rate",
        type=float,
        default=0.9,
        help="Speaking rate (1.0 = normal). Lower is slower, more deliberate.",
    )
    parser.add_argument(
        "--pitch",
        type=float,
        default=-2.0,
        help="Pitch in semitones. Negative = deeper.",
    )

    args = parser.parse_args()

    if not args.text and not args.text_file:
        parser.error("You must provide --text or --text-file")

    if args.text_file:
        with open(args.text_file, "r", encoding="utf-8") as f:
            text = f.read()
    else:
        text = args.text

    synthesize_zen_style(
        text=text,
        output_path=args.out,
        language_code="en-GB",
        voice_name=args.voice_name,
        speaking_rate=args.rate,
        pitch=args.pitch,
    )


if __name__ == "__main__":
    main()
