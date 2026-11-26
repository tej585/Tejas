import { Check, Lightbulb, X } from 'lucide-react'
import type { Question } from '@/lib/quiz-data'

type Props = {
  question: Question
  selected: number | null
  revealed: boolean
  onSelect: (index: number) => void
}

const letters = ['A', 'B', 'C', 'D']

export function QuestionCard({ question, selected, revealed, onSelect }: Props) {
  const correct = selected === question.answer
  const timedOut = revealed && selected === null

  return (
    <section className="flex flex-col gap-6 animate-in fade-in slide-in-from-bottom-2 duration-300">
      <h2 className="font-display text-3xl font-bold leading-tight text-balance md:text-4xl">{question.prompt}</h2>

      <ul className="grid gap-3 sm:grid-cols-2">
        {question.options.map((option, i) => {
          const isAnswer = i === question.answer
          const isPicked = i === selected

          let state = 'bg-card hover:bg-highlight/60 shadow-[3px_3px_0_0_var(--foreground)] hover:-translate-y-0.5'
          if (revealed) {
            if (isAnswer) state = 'bg-success text-success-foreground shadow-[3px_3px_0_0_var(--foreground)]'
            else if (isPicked) state = 'bg-destructive text-white shadow-[3px_3px_0_0_var(--foreground)]'
            else state = 'bg-card opacity-50'
          }

          return (
            <li key={option}>
              <button
                type="button"
                onClick={() => onSelect(i)}
                disabled={revealed}
                aria-pressed={isPicked}
                className={`flex w-full items-center gap-4 rounded-xl border-2 border-foreground p-4 text-left text-base font-medium transition-all focus-visible:outline-none focus-visible:ring-4 focus-visible:ring-ring disabled:cursor-default ${state} ${
                  revealed && isPicked && !isAnswer ? 'animate-shake' : ''
                }`}
              >
                <span className="flex size-8 shrink-0 items-center justify-center rounded-lg border-2 border-current text-sm font-bold">
                  {revealed && isAnswer ? (
                    <Check className="size-4" aria-hidden="true" />
                  ) : revealed && isPicked ? (
                    <X className="size-4" aria-hidden="true" />
                  ) : (
                    letters[i]
                  )}
                </span>
                <span className="flex-1">{option}</span>
                {!revealed && (
                  <kbd className="hidden rounded border border-foreground/20 px-1.5 text-xs text-muted-foreground sm:inline">
                    {i + 1}
                  </kbd>
                )}
                {revealed && isAnswer && <span className="sr-only">{'(correct answer)'}</span>}
                {revealed && isPicked && !isAnswer && <span className="sr-only">{'(your answer, incorrect)'}</span>}
              </button>
            </li>
          )
        })}
      </ul>

      <div aria-live="polite">
        {revealed && (
          <div className="flex items-start gap-3 rounded-xl border-2 border-dashed border-foreground/30 bg-card p-4 animate-in fade-in duration-300">
            <Lightbulb className="mt-0.5 size-5 shrink-0" aria-hidden="true" />
            <div className="flex flex-col gap-0.5">
              <p className="font-bold">
                {timedOut ? "Time's up!" : correct ? 'Correct!' : 'Not quite.'}
              </p>
              <p className="text-muted-foreground">{question.explanation}</p>
            </div>
          </div>
        )}
      </div>
    </section>
  )
}
