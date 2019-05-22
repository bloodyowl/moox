open BsReactNative;

let uri = "/me.png";
let width: Style.pt_only = Style.Pt(390. /. 1.4);
let height: Style.pt_only = Style.Pt(500. /. 1.4);

[@react.component]
let make = () => {
  <div
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~flexDirection="column",
      ~flex="1 1 auto",
      ~filter=
        [|
          "brightness(0.8)",
          "contrast(1.1)",
          "saturate(1.15)",
          "hue-rotate(-1deg)",
          "drop-shadow(0 0 20px rgba(0,0,0,0.2))",
        |]
        |> Js.Array.joinWith(" "),
      (),
    )}>
    <Image
      source={`URI(Image.(imageURISource(~uri, ~width, ~height, ())))}
      // SSR workaround https://github.com/necolas/react-native-web/issues/543
      defaultSource={
                      `URI(
                        Image.(defaultURISource(~uri, ~width, ~height, ())),
                      )
                    }
    />
  </div>;
};
